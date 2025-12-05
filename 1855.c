#include <stdio.h>
#include <stdbool.h>

#define MAX 100

char map[MAX][MAX];
bool visited[MAX][MAX];

int main() {
    int columns, rows;
    scanf("%d %d", &columns, &rows);
    
    for (int i = 0; i < rows; i++) {
        scanf("%s", map[i]);
    }
    
    int x = 0, y = 0;
    bool foundTreasure = false;
    
    while (true) {
        if (visited[x][y]) {
            break; // Loop infinito detectado
        }
        visited[x][y] = true;
        
        char currChar = map[x][y];
        if (currChar == '*') {
            foundTreasure = true;
            break;
        }
        if (currChar == '.') break;
        
        if (currChar == '<') {
            while (y > 0 && map[x][y - 1] == '.') y--;
            if (y > 0) y--;
        } else if (currChar == '>') {
            while (y < columns - 1 && map[x][y + 1] == '.') y++;
            if (y < columns - 1) y++;
        } else if (currChar == '^') {
            while (x > 0 && map[x - 1][y] == '.') x--;
            if (x > 0) x--;
        } else if (currChar == 'v') {
            while (x < rows - 1 && map[x + 1][y] == '.') x++;
            if (x < rows - 1) x++;
        }
    }
    
    printf("%c\n", foundTreasure ? '*' : '!');
    
    return 0;
}
