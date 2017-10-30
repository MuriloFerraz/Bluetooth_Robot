/*

----------- Versão 1.01 --------------

      Autor: Murilo Ferraz de Almeida
      murilof.almeida@hotmail.com
      murilo.ferraz125@gmail.com
      https://github.com/MuriloFerraz

                 10/2017

----------------------------------------

------- Objetivo / Requerimentos -------

    Este código foi escrito para controlar
    um robo esteira via Bluetooth

    HARDWARE
    1 Arduino ou compatível
    1 Modulo Bluetooth HC-05 ou HC-06
    1 TB6612FNG / L293D
    2 motores AC - 3V / TAMIYA TWIN-MOTOR GEARBOX

-----------------------------------------------
  Espero que este código lhe seja útil e seu projeto
  funcione corretamente.
  Não deixe de ler o arquivo de licença

      Sempre cite a fonte.


*/

 //
 #include "SoftwareSerial.h" // Biblioteca software serial

 // Criar um objeto Software Serial
 SoftwareSerial bluetooth(2, 3); // TX, RX (Bluetooth)
 char incomingByte; // Armazena o dado recebido via Bluetooth

 const int PWMA = 11; // Velocidade Motor A
 const int PWMB = 10; // Velocidade MOTOR B
 //const int STBY = 6; // Desabilite se estiver usando L293D

  const int AIN1 = 7; // Motor A - 1
  const int AIN2 = 8; // Motor A - 2

  const int BIN1 = 5; // Motor B - 1
  const int BIN2 = 4; // Motor B - 2

  int LED = 13; // LED

  


void setup() {
  // put your setup code here, to run once:
  bluetooth.begin(9600); // Inicia a comunicação serial via Bluetooth e o arduino

  // Os pinos a seguir serão selecionados como OUTPUT
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  //pinMode(STBY, OUTPUT); // Desabilitar se estiver usando L293D
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(LED , OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
if (bluetooth.available() > 0){
  // se comunicação com bluetooth estiver disponível...
  incomingByte = bluetooth.read();
  // armazena na variavel o ultimo byte recebido

  // aqui começa a brincadeira...
  if (incomingByte == 'F'){
    frente();
    }

  if (incomingByte == 'B'){
    rear();
    }  

  if (incomingByte == 'L'){
    esquerda();
    }  

  if (incomingByte == 'R'){
    direita();
    }

  if (incomingByte == 'S'){
    parado();
    }    
  }
}


void frente()  
{
  // o robo anda para frente 
  // digitalWrite(STBY, HIGH);  // Desabilite sempre que ocorrer se estiver a usar L293D
  
  analogWrite(PWMA, 255); //  0 - Parado /  255 Vel Máxima
  digitalWrite(AIN1, LOW); 
  digitalWrite(AIN2, HIGH);
  
  analogWrite(PWMB, 255); // 0 - Parado /  255 Vel Máxima
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  digitalWrite(LED, LOW);
}

void parado()
{
  // o robo esta parado
  // digitalWrite(STBY, LOW);
  
  analogWrite(PWMA, 0);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  
  analogWrite(PWMB, 0);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  digitalWrite(LED, LOW);
}

void esquerda()
{
  // um motor gira ao contario do outro
  // fazendo o robo girar
  // digitalWrite(STBY, HIGH);
  
  analogWrite(PWMA, 255);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  
  analogWrite(PWMB, 255);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  digitalWrite(LED, LOW);
}

void direita()
{
  // um motor gira ao contario do outro
  // fazendo o robo girar
  // digitalWrite(STBY, HIGH);
  
  analogWrite(PWMA, 255);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  
  analogWrite(PWMB, 255);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  digitalWrite(LED, LOW);
}


void rear()  
{
  // o robo anda para frente 
  // digitalWrite(STBY, HIGH);  // Desabilite sempre que ocorrer se estiver a usar L293D
  
  analogWrite(PWMA, 255); //  0 - Parado /  255 Vel Máxima
  digitalWrite(AIN1, HIGH); 
  digitalWrite(AIN2, LOW);
  
  analogWrite(PWMB, 255); // 0 - Parado /  255 Vel Máxima
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  digitalWrite(LED, HIGH); // Acende a luz de ré
}
