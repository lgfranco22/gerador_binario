# Gerador de Arquivo Binário com Padrão Repetitivo

Este é um programa em C que gera um arquivo binário (.bin) contendo um padrão repetido de bytes. O padrão gerado varia de `0x00` a `0xFF` e é repetido até que o tamanho do arquivo desejado seja atingido.

## Funcionalidade

O objetivo deste software é criar arquivos binários com padrões repetitivos, úteis para testar compressão de dados ou para outras finalidades onde padrões previsíveis em arquivos são necessários.

## Como o Programa Funciona

1. O programa solicita ao usuário:
   - O **nome do arquivo de saída** (ex.: `arquivo.bin`).
   - O **tamanho do arquivo** desejado em bytes.

2. Após receber os dados de entrada, o programa gera um arquivo binário com o padrão de repetição de 256 bytes (de `0x00` a `0xFF`), repetido até preencher o tamanho do arquivo especificado.

3. Se o tamanho não for múltiplo de 256, os bytes restantes do padrão serão escritos para completar o arquivo.

## Como Compilar

Você pode compilar o programa com um compilador C, como o **GCC**:

```bash
gcc -o gerador_binario gerador_binario_repeticao.c
```

Certifique-se de estar usando uma aplicação de **console** no Windows, ou adicione a flag `-mconsole` para garantir que o programa funcione corretamente:

```bash
gcc -mconsole -o gerador_binario gerador_binario_repeticao.c
```

## Como Executar

Depois de compilar o programa, execute-o no terminal:

```bash
./gerador_binario
```

O programa solicitará que você insira:
1. O nome do arquivo de saída.
2. O tamanho do arquivo em bytes.

Exemplo de execução:

```bash
Digite o nome do arquivo de saída (ex: arquivo.bin): arquivo.bin
Digite o tamanho do arquivo em bytes: 1048576
```

O programa então criará um arquivo binário de 1 MB com o padrão repetido de bytes.

## Requisitos

- Compilador C (recomendado: GCC)
- Sistema operacional Windows ou Linux

## Observações

- No Windows, para garantir que acentos sejam exibidos corretamente no console, utilize `setlocale(LC_ALL, "Portuguese");` dentro da função `main`.
- Arquivos gerados podem ser usados para testar compressão ou simular padrões em dados binários.

## Licença

Este projeto está licenciado sob a licença MIT.
