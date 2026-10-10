#include "header.h"


/* Add filename to list if not already present */

static void add_to_list(Slist_t **head, char *filename)
{
    Slist_t *temp = *head;

    while (temp != NULL)
    {
        if (strcmp(temp->file, filename) == 0)
        {
            return;
        }

        temp = temp->link;
    }


    Slist_t *new = malloc(sizeof(Slist_t));

    if (new == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }


    strcpy(new->file, filename);

    new->link = NULL;


    if (*head == NULL)
    {
        *head = new;
    }
    else
    {
        temp = *head;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = new;
    }
}



void update_database(hash_t *hash_table, Slist_t **head)
{
    char file[30];
    char line[200];

    int index;
    int fcount;
    int wcount;

    char word[30];
    char filename[30];


    printf("Enter the saved database file name: ");
    scanf("%29s", file);


    char *ptr = strrchr(file, '.');


    /* Check extension */

    if (ptr == NULL || strcmp(ptr, ".txt") != 0)
    {
        printf("Not a .txt file\n");
        return;
    }


    FILE *fp = fopen(file, "r");


    if (fp == NULL)
    {
        printf("File open failed\n");
        return;
    }


    m_node *main_n = NULL;
    s_node *last_sub = NULL;
    int remaining_files = 0;


    while (fgets(line, sizeof(line), fp) != NULL)
    {
        /*
         * Main node line format:
         *
         * #;7;hi;2;file2.txt;2;#
         *
         * OR continuation line:
         *
         * file3.txt;3;#
         */


        if (line[0] == '#')
        {
            /*
             * Read:
             *
             * #;index;word;fcount;filename;wcount;#
             */


            int result = sscanf(line,
                                "#;%d;%29[^;];%d;%29[^;];%d;#",
                                &index,
                                word,
                                &fcount,
                                filename,
                                &wcount);


            if (result != 5)
            {
                printf("Invalid database file format\n");

                fclose(fp);
                return;
            }


            /* Create main node */

            main_n = malloc(sizeof(m_node));


            if (main_n == NULL)
            {
                printf("Memory allocation failed\n");

                fclose(fp);
                return;
            }


            strcpy(main_n->words, word);

            main_n->f_count = fcount;

            main_n->m_link = NULL;

            main_n->s_link = NULL;


            /* Insert main node */

            if (hash_table[index].m_link == NULL)
            {
                hash_table[index].m_link = main_n;
            }
            else
            {
                m_node *temp_m = hash_table[index].m_link;

                while (temp_m->m_link != NULL)
                {
                    temp_m = temp_m->m_link;
                }

                temp_m->m_link = main_n;
            }


            /* Create first sub node */

            s_node *sub_n = malloc(sizeof(s_node));


            if (sub_n == NULL)
            {
                printf("Memory allocation failed\n");

                fclose(fp);
                return;
            }


            strcpy(sub_n->filename, filename);

            sub_n->w_count = wcount;

            sub_n->s_link = NULL;


            main_n->s_link = sub_n;

            last_sub = sub_n;


            /* Number of additional filenames */

            remaining_files = fcount - 1;


            /* Add filename to file list */

            add_to_list(head, filename);
        }


        else
        {
            /*
             * Continuation line format:
             *
             * file3.txt;3;#
             */


            if (main_n == NULL || remaining_files <= 0)
            {
                continue;
            }


            int result = sscanf(line,
                                "%29[^;];%d;#",
                                filename,
                                &wcount);


            if (result != 2)
            {
                printf("Corrupted database file\n");

                fclose(fp);
                return;
            }


            s_node *sub_n = malloc(sizeof(s_node));


            if (sub_n == NULL)
            {
                printf("Memory allocation failed\n");

                fclose(fp);
                return;
            }


            strcpy(sub_n->filename, filename);

            sub_n->w_count = wcount;

            sub_n->s_link = NULL;


            last_sub->s_link = sub_n;

            last_sub = sub_n;


            remaining_files--;


            add_to_list(head, filename);
        }
    }


    fclose(fp);


    printf("Database updated successfully\n");
}