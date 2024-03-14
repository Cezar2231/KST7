#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define COMMON_COUNT 8
#define MAXN 1024
#define LETTERS_COUNT 26

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

int* count_letters(char* cypher){
    int* counts = (int*)malloc(sizeof(int) * LETTERS_COUNT);
    memset(counts, 0, sizeof(int) * LETTERS_COUNT) ;
    int index = 0;
    while(cypher[index] != '\0'){
        char letter = tolower(cypher[index]);
        counts[letter - 'a']++;
        index++;
    }
    return counts;
}

int get_max_index(int* counts){
    int max_index = 0;
    for(int i=0; i<LETTERS_COUNT; i++){
        if(counts[i] > counts[max_index]){
            max_index = i;
        }
    }
    return max_index;
}

char most_common_letter(char* cypher){
    int* counts = count_letters(cypher);
    int max_index = get_max_index(counts);
    char letter = max_index + 'a';
    return letter;
}
 


char* read_cypher(char* filename)
{
    FILE* file = fopen(filename, "r");
    
    if (file == NULL)
    {
        printf("Error opening the file.");
        return NULL;
    }
    
    char* cypher = (char*) malloc( MAXN * sizeof(char) );
    if(fgets(cypher, MAXN, file) == NULL)
    {
        printf("Error reading from file.");
        return NULL;
    }
    
    fclose(file);
    return cypher;
}

int main()
{
    char filename[1024];
    scanf("%s", filename);
    
    char* cypher = read_cypher(filename);
    
    char common_letters[COMMON_COUNT] = {'e', 'a', 'r', 't','o','i','n','s'};
    for(int i = 0; i < COMMON_COUNT; i++)
    {
        int key = most_common_letter(cypher) - common_letters[i];
        printf("key = %d\n", key);
        char* text = caesar_cypher(cypher, key);
        printf("%s\n", text);
        printf("--------------\n");
    }
    
    
}
