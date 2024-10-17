#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");  // Configura a localidade para suportar acentuação

    FILE *file;
    char filename[256];
    unsigned long file_size;
    unsigned char pattern[256]; // Padrão de repetição de 0x00 a 0xFF
    unsigned long i, j;

    // Preenche o padrão com valores de 0x00 a 0xFF
    for (i = 0; i < 256; i++) {
        pattern[i] = (unsigned char)i;
    }

    // Solicita o nome do arquivo
    printf("Digite o nome do arquivo de saída (ex: arquivo.bin): ");
    scanf("%255s", filename);

    // Solicita o tamanho do arquivo
    printf("Digite o tamanho do arquivo em bytes: ");
    scanf("%lu", &file_size);

    // Abre o arquivo para escrita binária
    file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Escreve o padrão repetido até atingir o tamanho do arquivo desejado
    for (i = 0; i < file_size / 256; i++) {
        fwrite(pattern, sizeof(unsigned char), 256, file); // Escreve 256 bytes (0x00 a 0xFF)
    }

    // Se o tamanho do arquivo não for múltiplo de 256, escreve o resto
    if (file_size % 256 != 0) {
        fwrite(pattern, sizeof(unsigned char), file_size % 256, file);
    }

    // Fecha o arquivo
    fclose(file);

    printf("Arquivo '%s' de %lu bytes criado com sucesso!\n", filename, file_size);

    return 0;
}
