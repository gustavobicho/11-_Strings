#include <Arduino.h> // Biblioteca principal do Arduino (permite usar funções como Serial, setup, loop)
#include <string.h>  // Biblioteca de strings em C (funções como strcpy, strlen, strcmp, etc)

// ---------------------- STRINGS EM C ----------------------

// String declarada manualmente com terminador '\0' (fim da string em C)
char primeiroNomeExplicito[6] = {'A', 'r', 't', 'u', 'r', '\0'};

// Forma mais comum: o compilador adiciona automaticamente o '\0'
char primeiroNomeImplicito[6] = "Artur";

// ---------------------- STRING DO ARDUINO ----------------------

// Classe String do Arduino (mais fácil de usar que char[])
String nomeCompleto = "Artur";

void setup()
{
  Serial.begin(9600); // Inicia comunicação serial com taxa de 9600 bps
  Serial.println();   // Imprime uma linha em branco

  // ---------------------- CONCATENAÇÃO ----------------------

  nomeCompleto = nomeCompleto + " Medeiros"; // Junta duas strings
  Serial.println(nomeCompleto); // Mostra "Artur Medeiros"

  // ---------------------- TAMANHO ----------------------

  int tamanho = nomeCompleto.length(); // Retorna quantidade de caracteres
  Serial.println(tamanho);

  // ---------------------- ACESSO A CARACTERE ----------------------

  char letra = nomeCompleto.charAt(5); // Pega caractere na posição 5
  Serial.println(letra);

  Serial.println(nomeCompleto[5]); // Outra forma de acessar caractere (igual array)

  // ---------------------- CONVERSÃO ----------------------

  const char *textoConvertido = nomeCompleto.c_str(); 
  // Converte String Arduino para string C (char*)

  Serial.println(textoConvertido);

  // ---------------------- STRING C ----------------------

  const char *cidade = "Sao Paulo"; // Ponteiro para string constante

  int tamanhoCidade = strlen(cidade); // Calcula tamanho da string (sem contar '\0')
  Serial.println(tamanhoCidade);

  // ---------------------- CÓPIA ----------------------

  strcpy(primeiroNomeExplicito, "Senai"); 
  // Copia "Senai" para o vetor de caracteres

  // ---------------------- COMPARAÇÃO ----------------------

  if (strcmp(primeiroNomeExplicito, "Senai") == 0)
    Serial.println("São iguais"); // strcmp retorna 0 se forem iguais
  else if (strcmp(primeiroNomeExplicito, "Senai") > 0)
    Serial.println("Maior na ordem lexica"); // ordem alfabética
  else
    Serial.println("Menor na ordem lexica");

  // ---------------------- COMPARAÇÃO PARCIAL ----------------------

  if (strncmp(cidade, "Sao", 3) == 0)
    Serial.println("Primeiras letras iguais"); 
  // Compara apenas os 3 primeiros caracteres

  // ---------------------- BUSCA ----------------------

  if (strstr(cidade, "Paulo"))
    Serial.println("Encontrou Paulo"); 
  // Procura substring dentro da string

  // ---------------------- TAMANHO NOVAMENTE ----------------------

  Serial.print("A string tem ");
  Serial.print(strlen(cidade)); // tamanho novamente
  Serial.println(" letras");

  // ---------------------- TEXTO PARA NÚMERO ----------------------

  strcpy(primeiroNomeExplicito, "45");

  int numero = atoi(primeiroNomeExplicito); 
  // Converte string para inteiro

  Serial.println(numero * 2); // Multiplica o número por 2

  // ---------------------- CONCATENAÇÃO EM C ----------------------

  char frase[30]; // Vetor para armazenar frase final

  strcpy(frase, primeiroNomeImplicito); // Copia "Artur"
  strcat(frase, " ");                   // Adiciona espaço
  strcat(frase, primeiroNomeExplicito); // Adiciona "45"

  Serial.println(frase); // Exibe "Artur 45"

  //------------------------ String ----------------------------

  String palavra3 = "HOJE EH QUINTA!";

  Serial.println(palavra3.length());    // Tamanho da string
  Serial.println(palavra3.charAt(8));   // Caractere na posição 8

  Serial.println(palavra3.indexOf('Q')); // Primeira posição de 'Q'
  Serial.println(palavra3.substring(8, 14)); // Extrai parte da string

  Serial.println(palavra3.indexOf('E'));     // Primeiro 'E'
  Serial.println(palavra3.lastIndexOf('E')); // Último 'E'

  // Comparação exata
  if (palavra3.equals("HOJE EH SEXTA"))
    Serial.println("Hoje é sexta!!!!");
  else
    Serial.println("Erroooouuuu hoje não é sexta");

  // Comparação ignorando maiúsculas/minúsculas
  if (palavra3.equalsIgnoreCase("hoje eh quinta!"))
    Serial.println("Sim, hoje ainda é quinta.");

  // Verifica início da string
  if (palavra3.startsWith("HOJE"))
    Serial.println("A string começa com a palavra HOJE");

  // Verifica final da string
  if (palavra3.endsWith("INTA!"))
    Serial.println("A string termina com INTA!");

  String valor = "123";

  int valorNumerico = valor.toInt(); // Converte para inteiro
  Serial.println(valorNumerico * 10);

  //* EXEMPLO: Transforme o numero do texto em valor numérico e multiplique por 2

  String mensagem = "valor = 32.45";

  Serial.println(mensagem.toFloat()); // Converte texto para float (pega número dentro da string)

  int tamanhoString = mensagem.length();

  if (mensagem.startsWith("valor ="))
  {
    String extracao = mensagem.substring(8, tamanhoString); 
    // Extrai apenas o número "32.45"

    Serial.println(extracao);

    float numeroConvertido = extracao.toFloat(); // Converte para float
    Serial.println(numeroConvertido * 2);
  }

  //! CONTINUANDO

  palavra3.toLowerCase(); // Converte tudo para minúsculo
  Serial.println(palavra3);

  palavra3.toUpperCase(); // Converte tudo para maiúsculo
  Serial.println(palavra3);

  String textoLed = "Led = ON";
  textoLed.replace("ON", "OFF"); // Substitui ON por OFF
  Serial.println(textoLed);

  String novaFrase = "texto     ";
  Serial.println(novaFrase);

  // Comparação com espaços extras
  if (novaFrase.equals("texto"))
    Serial.println("São iguais");
  else
    Serial.println("Não são iguais");

  novaFrase.trim(); // Remove espaços no começo e fim

  if (novaFrase.equals("texto"))
    Serial.println("São iguais");
  else
    Serial.println("Não são iguais");

  novaFrase.concat(" final"); // Adiciona texto ao final
  Serial.println(novaFrase);

  novaFrase = novaFrase + " do final"; // Outra forma de concatenar
  Serial.println(novaFrase);

  const char *vetorCaracteres = novaFrase.c_str(); 
  // Converte String para char*

  Serial.println("Oi");
}

void loop()
{
  // Loop principal (fica repetindo infinitamente)
}