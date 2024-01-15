#include "HeadRingList.h"
#include <stddef.h>
#include <stdio.h>
#include <locale.h>

int main() {
    struct Node* head = NULL;
    setlocale(LC_ALL, "ru");

    int choice;
    int value;

    do {
        printf("Выберите действие:\n");
        printf("1. Добавить элемент\n");
        printf("2. Удалить элемент\n");
        printf("3. Вывести список\n");
        printf("4. Завершить программу\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Введите значение для добавления: ");
            scanf("%d", &value);
            head = insertNode(head, value);
            break;
        case 2:
            printf("Введите значение для удаления: ");
            scanf("%d", &value);
            head = deleteNode(head, value);
            break;
        case 3:
            printf("Элементы кольцевого списка:\n");
            displayList(head);
            break;
        case 4:
            break;
        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }

    } while (choice != 0);

    freeList(head);

    return 0;
}
