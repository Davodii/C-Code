#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    char *name;
    int age; 
    struct person *nextPerson;
} person_t;

person_t* createPerson(const char *name, int age, person_t* next){
    person_t *new = (person_t *)malloc(sizeof(person_t));
    new->name = name;
    new->age = age;
    return new;
}

void addFirst(person_t **head, person_t *newPerson){
    newPerson->nextPerson = *head;
    *head = newPerson;
}

void addLast(person_t *head, person_t* newPerson){
    person_t *current = head;
    while (current->nextPerson != NULL)
    {
        current = current->nextPerson;
    }
    current->nextPerson = newPerson;
    current->nextPerson->nextPerson = NULL;
}

void removeFirst(person_t **head){
    person_t *next_person = NULL;
    if(*head == NULL){
        return;
    }
    next_person = (*head)->nextPerson;
    free(*head);
    *head = next_person;
}

void removeLast(person_t *head){
    person_t* current = head;

    if(head->nextPerson == NULL){
        free(head);
        return;
    }
    while (current->nextPerson->nextPerson == NULL){
        current = current->nextPerson;
    }
    free(current->nextPerson);
    current->nextPerson == NULL;
}

void printPersonDetails(person_t *node){
    printf("%s\n", node->name);
    printf("%d\n", node->age);
}

int main(){
    person_t *head = createPerson("David Bob", 12, NULL);

    printPersonDetails(head);

    free(head);
    return 0;
}