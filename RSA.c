#include <stdio.h>
#include <string.h>

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                  'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                  's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                  'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                  'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                  '.', ',', ' ', '?'};

    int p, q, n, pn, e, d, k, digits;
    char pText[1000];
    char cText[1000] = "";

    printf("Input the normal text: ");
    fgets(pText, sizeof(pText), stdin);
    printf("Enter two large prime numbers: ");
    scanf("%d %d", &p, &q);

    n = p * q;
    digits = snprintf(NULL, 0, "%d", n);
    pn = (p - 1) * (q - 1);

    for (e = 2; e < pn; e++) {
        if (pn % e != 0) {
            break;
        }
    }
    for(k=1; k<1000; k++){
        d = (1 + k*pn) / e;
        if(d * e == 1 + k*pn) break;
    }

    for (int i = 0; pText[i] != '\0'; i++) {
        for (int j = 0; j < sizeof(arr); j++) {
            if (arr[j] == pText[i]) {
                if (j < 10) {
                    char temp[2];
                    snprintf(temp, sizeof(temp), "%d", j);
                    strcat(cText, temp);
                } else {
                    char temp[3];
                    snprintf(temp, sizeof(temp), "%d", j);
                    strcat(cText, temp);
                }
                break;
            }
        }
    }

    int x = digits - 1;
    int len = strlen(cText);
    int numportionss = (len + x - 1) / x;
    char portions[1000][10] = {};

    int idx = 0;
    for (int i = 0; i < numportionss; i++) {
        int length = (x < len - idx) ? x : len - idx;
        strncpy(portions[i], &cText[idx], length);
        idx += length;
    }

    for (int i = 0; i < numportionss; i++){
        int chunkValue = atoi(portions[i]);

        int EV = 1;
        for (int j = 0; j < e; j++){
            EV = (EV * chunkValue) % n;
        }

        int DV = 1;
        for (int j = 0; j < d; j++){
            DV = (DV * EV) % n;
        }

        printf("M%d = %s\t", i + 1, portions[i]);
        printf("C%d = %d\t", i + 1, EV);
        printf("P%d = %d\n", i + 1, DV);
    }
}
