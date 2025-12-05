#include <stdio.h>
#include <string.h>
#include <ctype.h>

int senha_valida(const char *senha) {
    int tem_maiuscula = 0, tem_minuscula = 0, tem_numero = 0;
    int tamanho = strlen(senha);

    // Verifica o tamanho
    if (tamanho < 6 || tamanho > 32) return 0;

    for (int i = 0; i < tamanho; i++) {
        char c = senha[i];

        // Verifica se contém apenas letras e números
        if (!isalnum(c)) return 0;
        if (isupper(c)) tem_maiuscula = 1;
        if (islower(c)) tem_minuscula = 1;
        if (isdigit(c)) tem_numero = 1;
    }

    return (tem_maiuscula && tem_minuscula && tem_numero);
}

int main() {
    char senha[100];

    while (fgets(senha, sizeof(senha), stdin)) {
        // Remove o '\n' do final da string
        senha[strcspn(senha, "\n")] = 0;

        if (senha_valida(senha)) {
            printf("Senha valida.\n");
        } else {
            printf("Senha invalida.\n");
        }
    }

    return 0;
}
