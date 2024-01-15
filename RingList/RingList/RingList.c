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
        printf("�������� ��������:\n");
        printf("1. �������� �������\n");
        printf("2. ������� �������\n");
        printf("3. ������� ������\n");
        printf("4. ��������� ���������\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("������� �������� ��� ����������: ");
            scanf("%d", &value);
            head = insertNode(head, value);
            break;
        case 2:
            printf("������� �������� ��� ��������: ");
            scanf("%d", &value);
            head = deleteNode(head, value);
            break;
        case 3:
            printf("�������� ���������� ������:\n");
            displayList(head);
            break;
        case 4:
            break;
        default:
            printf("�������� �����. ���������� �����.\n");
        }

    } while (choice != 0);

    freeList(head);

    return 0;
}
