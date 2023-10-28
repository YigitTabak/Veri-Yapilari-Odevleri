#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Ba�l� liste d���m yap�s�
struct Node {
    int data;
    char studentName[50];
    int studentAge;
    struct Node* next;
};

// Yeni bir d���m olu�turan fonksiyon
struct Node* newNode(int number, char *name, int age) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = number;
    strcpy(node->studentName, name);
    node->studentAge = age;
    node->next = NULL;
    return node;
}

// Klavyeden -1 girilinceye kadar, girilen t�m tek say�lar� listenin ba��na, �ift say�lar� ise listenin sonuna ekleyen fonksiyon
void TekCift() {
    struct Node* head = NULL;
    int input;
    printf("Sayilari girin (-1 girildiginde sonlanir):\n");
    while (1) {
        scanf("%d", &input);
        if (input == -1) {
            break;
        }
        struct Node* new_node = newNode(input, "", 0);
        if (input % 2 != 0) {
            new_node->next = head;
            head = new_node;  // Tek say�lar� ba�a ekle
        } else {
            if (head == NULL) {
                head = new_node;
            } else {
                struct Node* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = new_node;  // �ift say�lar� sona ekle
            }
        }
    }
    printf("Yeniden duzenlenmis liste: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Ba�l� listeye yeni bir d���m ekleyen fonksiyon
void addNode(struct Node** head_ref, int new_data, char *name, int age) {
    struct Node* new_node = newNode(new_data, name, age);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node* temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Ba�l� listeyi b�y�kten k����e s�ralayan fonksiyon
void KucuktenBuyuge(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* index = NULL;
    int temp;

    if (current == NULL) {
        return;
    } else {
        while (current != NULL) {
            index = current->next;

            while (index != NULL) {
                if (current->data < index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

// Ba�l� listeyi ekrana yazd�ran fonksiyon
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d", node->data);
        if (node->next != NULL) {
            printf("->");
        }
        node = node->next;
    }
    printf("\n");
}

// Ba�l� liste d���mlerini dola�an ve ��renci bilgilerini ekrana yazan fonksiyon
void OgrenciYazdir(struct Node* head) {
    int count = 1;
    printf("Ogrenci Bilgileri:\n");
    while (head != NULL) {
        printf("%d- %s %d %d\n", count, head->studentName, head->studentAge, 200 + count);
        count++;
        head = head->next;
    }
}

// Listede ��renci ad�na g�re kay�t arama yapan fonksiyon
struct Node* IsimArama(struct Node* head, char *name) {
    while (head != NULL) {
        if (strcmp(head->studentName, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Listede aranan ��renci ad�n�n yer ald��� d���mden bir sonraki d���m� silen fonksiyon
void Silme(struct Node* node) {
    if (node == NULL || node->next == NULL) {
        return;
    }
    struct Node* next = node->next;
    node->next = next->next;
    free(next);
}

// Listede en uzun ismin oldu�u kayd� yazd�ran fonksiyon
void EnUzunIsim(struct Node* head) {
    int max_length = 0;
    char longestName[50] = "";
    while (head != NULL) {
        int current_length = 0;
        char* currentName = head->studentName;
        while (*currentName != '\0') {
            current_length++;
            currentName++;
        }
        if (current_length > max_length) {
            max_length = current_length;
            strcpy(longestName, head->studentName);
        }
        head = head->next;
    }
    printf("Listedeki en uzun isim: %s\n", longestName);
    printf("Uzunluk: %d\n", max_length);
}

// Ana fonksiyon
int main() {
	int choice;
	 printf("Lutfen bir fonksiyon secin (1(tekcift), 2(kucukbuyuk), 3(ogrenciyazd�r) ,4(isimarama),5(silme),6(enzunisim)): ");
    scanf("%d", &choice);
    


    switch (choice) {
        case 1:
            TekCift();
            break;
        case 2:
            struct Node* head = NULL;
    int i, num;
    srand(time(0));
    for (i = 0; i < 100; i++) {
        num = rand() % 1000;
        addNode(&head, num, "", 0);
    }
    printf("S�ralanm�� liste: ");
    KucuktenBuyuge(&head);
    printList(head);
            break;
        case 3:
            OgrenciYazdir(head);
            break;
        case 4:
            IsimArama();
            break;
        case 5:
              Silme();
            break;
        case 6:
               EnUzunIsim();
            break;
        default:
            defaultFunction();
    }
    

    return 0;
}

