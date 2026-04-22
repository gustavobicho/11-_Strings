#include <Arduino.h>



//\0 É um terminador
char primeiroNomeExplicito[6] = {'A', 'r', 't', 'u', 'r', '\0'};
char primeiroNomeImplicito[6] = {'A', 'r', 't', 'u', 'r'};

//O terminador \0 está implícito na String
String nomeCompleto = "Artur";

void setup() 
{
  Serial.begin(9600);
  Serial.println(); //Uma quebra para ruído

  //Quando é uma operação, a concatenação irá funcionar no setup, no loop, ou em outras funções 
  nomeCompleto = nomeCompleto + " Medeiros";

  // Serial.println(primeiroNomeExplicito);
  // Serial.println(primeiroNomeImplicito);
  // Serial.println(nomeCompleto);

  //A partir de uma string, acessamos um dos métodos para mostrar o comprimento da mesma
  int tamanhoDaPalavra = nomeCompleto.length();

  //Serial.println(tamanhoDaPalavra);

  //charAt retorna o valor da respectiva posição escolhida
  char primeiraLetra = nomeCompleto.charAt(5);

  //Serial.println(primeiraLetra);

  //Acessa através do colchetes a respectiva posição da minha string
  //Serial.println(nomeCompleto[5]);

 //String nomeCurso = "Desenvolvimento de Sistemas";

  //Serial.println(nomeCurso.indexOf("Sistemas"));

  //nomeCurso.replace("Sistemas", "Games");

  //Serial.println(nomeCurso);
  //nomeCurso.toUpperCase(); //Transforma o texto em maiusculo
  //nomeCurso.toLowerCase(); //Transforma o texto em minusculo

  //Serial.println(nomeCurso);

//String numeroString = "2026";
//int numeroConvertido = numeroString.toInt(); //converte String para inteiro

//Serial.println(numeroConvertido);

//String textoDigitado = "";

//if (textoDigitado.length() == 0)
//{
 // Serial.println("Texto vazio");
//}
//else
//{
 // Serial.println("Ha texto");
//}

// * -> indica ponteiro, ou seja, guarda o endereço de memoria de uma valor fixo ou de uma variável somente leitura (const)
const char* conversaoStringEmC = nomeCompleto.c_str();
//Serial.println(conversaoStringEmC);

// é uma cadeia de caractere sem tamanho definido
const char *cidade = "Sao Paulo";
//Serial.println(cidade);

int tamanhoCidade = strlen(cidade);

Serial.println(tamanhoCidade);
}

void loop()
{

}




