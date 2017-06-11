/************************************************************************************//**
 *  @file       main.c
 *
 *  @brief      Brief descriptinon of main.c
 *
 *  @date       2017-05-13 03:45
 *
 ***************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "iterator.h"
#include "point.h"
#include "my_fscanf.h"


LinkedList *readCommand(char *commandFileName) {
    FILE *fp = fopen(commandFileName, "r");
    char command[255];
    bool isSuccess = true;
    int line;
    LinkedList *list = newLinkedList(sizeof(Point*));

    if(fp!=NULL) {
        my_fscanf(fp, "%d", &line);
        for(int i = 0; i < line; i++) {
            my_fscanf(fp, "%s", command);
            if(feof(fp)) break;
            if(strcmp(command, "add") == 0) {
                // add a point into the list
                double x, y;
                char type[10];
                // example: point (0,0)
                my_fscanf(fp, "%s (%f,%f)", type, &x, &y);
                if(strcmp(type, "point") == 0) {
                    Point *p = newPoint(x, y);
                    list->add(list, p);
                } else {
                    fprintf(stderr, "Error: unknown type (%d line).\n", i+2);
                    isSuccess = false;
                    break;
                }
            } else if(strcmp(command, "insert") == 0) {
                // insert a point at the given index into the list
                // TODO:
                // example: point (0,0) 0
				double x, y;
				int index;
				char type[10];
				my_fscanf(fp, "%s (%f,%f) %d", type, &x, &y, &index);
				if (strcmp(type, "point") == 0) {
					Point *p = newPoint(x, y);
					list->insert(list, index, p);
				}
				else {
					fprintf(stderr, "Error: unknown type (%d line).\n", i + 2);
					isSuccess = false;
					break;
				}

            } else if(strcmp(command, "remove") == 0) {
                // remove a point at the given index from the list
                // TODO:
                // example: 0
				int index;
				my_fscanf(fp, "%d", &index);
				deletePoint(list->remove(list, 0));
            } else {
                // error
                fprintf(stderr, "Error: unknown command (%d line).\n", i+2);
                isSuccess = false;
                break;
            }
        }
    }
    fclose(fp);

    if(!isSuccess) {
        list->delete(list);
        return NULL;
    }

    return list;
}

int main(int argc, char *argv[]) {
    LinkedList *list;
    if(argc > 1)
        list = readCommand(argv[1]);
    else 
      list = readCommand("command.txt");

    if(list == NULL)
        return EXIT_FAILURE;

    printf("After read commands\n");
    Iterator *iter = list->iterator(list);
    while(iter->hasNext(iter)) {
        Point *p = iter->next(iter);
        printf("List: (%f, %f)\n", p->getX(p), p->getY(p));
    }

    iter->delete(iter);

    printf("Storing the list in a binary file.\n");
    FILE *fp = fopen("points.bin", "w+b");

    list->writeObject(list, fp);
    list->delete(list);
	
    rewind(fp);

    printf("Loading the list from the binary file.\n");
    list = newLinkedList(sizeof(Point*));
    list->readObject(list, fp);

   /* iter = list->iterator(list);

    while(iter->hasNext(iter)) {
        Point *p = iter->next(iter);
        printf("List: (%f, %f)\n", p->getX(p), p->getY(p));
    }*/

	iter->delete(iter);
    list->delete(list);

    return EXIT_SUCCESS;
}

