#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char str[25], vol[] = {'a','e','i','o','u'};
    int frq[26] = {0};
    int i,j;
    int n_vol = 0,n_con = 0;

    printf("Enter the First String : ");
    scanf("%s", str);

    for (i = 0; i < strlen(str); i++){
        str[i] = tolower((unsigned char)str[i]);
        if (isalpha((unsigned char)str[i])) {
            frq[str[i] - 'a']++;
        }
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
        if (
            (i + 'a' == vol[0]) ||
            (i + 'a' == vol[1]) ||
            (i + 'a' == vol[2]) ||
            (i + 'a' == vol[3]) ||
            (i + 'a' == vol[4])
        ){
            n_vol += frq[i];
        }
        else{
            n_con += frq[i];
        }
    }

    printf("\n\t Number of vowels: %d", n_vol);
    printf("\n\t Number of consonants: %d", n_con);

    return 0;
}
