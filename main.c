#include "header.h"

int main(int argc, char *argv[])
{
    int option;

    Slist_t *head = NULL;

    hash_t hash_table[28];


    /* Check command line arguments */

    if (argc <= 1)
    {
        printf("Error: Invalid Command lines\n");
        return 0;
    }


    /* Validate input files */

    for (int i = 1; i < argc; i++)
    {
        validation(&head, argv[i]);
    }


    /* Initialize hash table */

    for (int i = 0; i < 28; i++)
    {
        hash_table[i].index = i;

        hash_table[i].m_link = NULL;
    }


    do
    {
        printf("\n");
        printf("\t\t::: INVERTED SEARCH PROJECT :::\n");

        printf("1. Create Database\n");
        printf("2. Display Database\n");
        printf("3. Save Database\n");
        printf("4. Search Database\n");
        printf("5. Update Database\n");
        printf("6. Exit\n");

        printf("Enter the option: ");

        scanf("%d", &option);


        switch (option)
        {
            case 1:

                create_database(hash_table, head);

                break;


            case 2:

                display_database(hash_table);

                break;


            case 3:

                save_database(hash_table);

                break;


            case 4:

                search_database(hash_table);

                break;


            case 5:

                update_database(hash_table, &head);

                break;


            case 6:

                printf("Exiting program...\n");

                break;


            default:

                printf("Invalid option\n");
        }

    } while (option != 6);


    return 0;
}