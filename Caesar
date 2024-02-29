#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* caesar_cypher(char* str, int key)
{
    int length = strlen(str);
    
    char* cypher = (char*) malloc((length + 1) * sizeof(char));
    
    int i = 0;
    while(str[i] != '\0')
    {
        cypher[i] = (str[i] - 'a' + key) % 26 + 'a';
        i++;
    }
    cypher[i] = '\0';
    return cypher;
}


int main()
{
    const int MAXN = 1024;
    char str[MAXN];
    scanf("%s", str);
    
    int key;
    scanf("%d", &key);
    
    char* cypher = caesar_cypher(str, key);
    
    printf("%s\n", cypher);
    
    for(int i = 0; i < strlen(cypher); i++)
    {
        printf("%d ", cypher[i]);
    }
}
