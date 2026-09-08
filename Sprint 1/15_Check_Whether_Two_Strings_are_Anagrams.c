#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char str1[25], str2[25];
    int frq1[26] = {0}, frq2[26] = {0};
    int i,j,ang = 1;

    printf("Enter the First String : ");
    scanf("%s", str1);
    printf("Enter the Second String : ");
    scanf("%s", str2);

    for (i = 0; i < strlen(str1); i++){
        str1[i] = tolower(str1[i]);
        for (j=0; j < 26; j++){
            if (str1[i] == (j + 'a')){
                frq1[j]++;
            }
        }
    }

    for (i = 0; i < strlen(str2); i++){
        str2[i] = tolower(str2[i]);
        frq2[str2[i]-'a']++;
        /*
        Same as
        for (j=0; j < 26; j++){
            if (str1[i] == (j + 'a')){
                frq1[j]++;
            }
        }
        */
    }

    for (i = 0; i < 26; i++){
        if (frq1[i] != frq2[i]){
            ang = 0;
            break;
        }
    }

    if (ang == 1){
        printf("\n\t %s and %s are Anagrams", str1, str2);
    }
    else{
        printf("\n\t %s and %s are not Anagrams", str1, str2);
    }

    return 0;
}
