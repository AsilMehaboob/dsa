#include <stdio.h>

int s1[100][3], s2[100][3], s3[100][3];

int create(int s[][3], int r, int c) {
    int val, k = 1;

    s[0][0] = r;
    s[0][1] = c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &val);
            if (val != 0) {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = val;
                k++;
            }
        }
    }
    s[0][2] = k - 1;

    return k;
}

void display(int s[][3], int t) {
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }
}

int addmatrix(int s1[][3], int s2[][3], int t1, int t2, int r, int c) {
    s3[0][0] = r;
    s3[0][1] = c;
    int i = 1, j = 1, k = 1;

    while (i <= t1 && j <= t2) {
        if (s1[i][0] == s2[j][0]) {
            if (s1[i][1] == s2[j][1]) {
                s3[k][0] = s1[i][0];
                s3[k][1] = s1[i][1];
                s3[k][2] = s1[i][2] + s2[j][2];
                k++;
                i++;
                j++;
            } else if (s1[i][1] > s2[j][1]) {
                s3[k][0] = s2[j][0];
                s3[k][1] = s2[j][1];
                s3[k][2] = s2[j][2];
                k++;
                j++;
            } else {
                s3[k][0] = s1[i][0];
                s3[k][1] = s1[i][1];
                s3[k][2] = s1[i][2];
                k++;
                i++;
            }
        } else if (s1[i][0] < s2[j][0]) {
            s3[k][0] = s1[i][0];
            s3[k][1] = s1[i][1];
            s3[k][2] = s1[i][2];
            k++;
            i++;
        } else {
            s3[k][0] = s2[j][0];
            s3[k][1] = s2[j][1];
            s3[k][2] = s2[j][2];
            k++;
            j++;
        }
    }
    while (j <= t2) {
        s3[k][0] = s2[j][0];
        s3[k][1] = s2[j][1];
        s3[k][2] = s2[j][2];
        k++;
        j++;
    }
    while (i <= t1) {
        s3[k][0] = s1[i][0];
        s3[k][1] = s1[i][1];
        s3[k][2] = s1[i][2];
        k++;
        i++;
    }
    s3[0][2] = k - 1;

    return k;
}

int main() {
    int r, c;
    int t1, t2, t3;
    printf("Enter Rows and Cols: ");
    scanf("%d%d", &r, &c);
    
    printf("Enter Matrix 1:\n");
    t1 = create(s1, r, c);
    display(s1, t1);

    printf("Enter Matrix 2:\n");
    t2 = create(s2, r, c);
    display(s2, t2);

    printf("Matrix 3:\n");
    t3 = addmatrix(s1, s2, t1, t2, r, c);
    display(s3, t3);

    return 0;
}
