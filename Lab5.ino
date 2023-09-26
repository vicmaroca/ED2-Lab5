//VARIABLES
#define LEDR RED_LED //Led rojo
#define LEDV GREEN_LED //Led verde
#define boton PB_5 //BotonSemaforo
#define SW1 PUSH1 //BotonJ1
#define SW2 PUSH2 //BotonJ2

const int LED1 = PB_0;
const int LED2 = PB_1;
const int LED3 = PE_4;
const int LED4 = PE_5;
const int LED5 = PB_4;
const int LED6 = PA_5;
const int LED7 = PA_6;
const int LED8 = PA_7;

const int LED9 = PB_2;
const int LED10 = PE_0;
const int LED11 = PF_0;
const int LED12 = PB_7;
const int LED13 = PB_6;
const int LED14 = PA_4;
const int LED15 = PA_3;
const int LED16 = PA_2;

const int LED17 = PC_7;
const int LED18 = PD_6;

int buttonState = 0;
int buttonState1 = 0;
int buttonState2 = 0;
int contador1 = 0;
int contador2 = 0;
int JUGADOR2 = 0;
int inicio = 0;
int ganaP1 = 0;
int ganaP2 = 0;


//FUNCIONES
void semaforo() {
  //ROJO
  digitalWrite(LEDR, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(3000);               // wait for a second
  digitalWrite(LEDR, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);               // wait for a second

  //AMARILLO
  digitalWrite(LEDR, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LEDV, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(LEDR, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(LEDV, LOW);   // turn the LED on (HIGH is the voltage level)
  //delay(1000);               // wait for a second

  //VERDE
  digitalWrite(LEDV, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(2000);               // wait for a second
  digitalWrite(LEDV, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);               // wait for a second
}


// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(LEDR, OUTPUT);
  pinMode(LEDV, OUTPUT);
  pinMode(boton, INPUT_PULLUP);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);

  pinMode(LED9, OUTPUT);
  pinMode(LED10, OUTPUT);
  pinMode(LED11, OUTPUT);
  pinMode(LED12, OUTPUT);
  pinMode(LED13, OUTPUT);
  pinMode(LED14, OUTPUT);
  pinMode(LED15, OUTPUT);
  pinMode(LED16, OUTPUT);

  pinMode(LED17, OUTPUT);
  pinMode(LED18, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  buttonState = digitalRead(boton);
  buttonState1 = digitalRead(SW1);
  buttonState2 = digitalRead(SW2);

  if (inicio == 0 && buttonState2 == LOW) {
    delay(200);
    semaforo ();
    inicio = 1;
    contador2=0;
  } else {
    delay(200);
    digitalWrite(LEDR, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(LEDV, LOW);
  }

  if (inicio == 1 && buttonState1 == LOW && ganaP2 == 0) {
    delay(200);
    contador1++;
  }

  if (inicio == 1 && buttonState == LOW && ganaP1 == 0) {
    delay(200);
    contador2++;
  }

  if (contador1 >= 8){
    digitalWrite(LED17, HIGH);
    //digitalWrite(LED18, HIGH);
    ganaP1 = 1;
    }

  if (contador2 >= 8){
    //digitalWrite(LED17, HIGH);
    digitalWrite(LED18, HIGH);
    ganaP2 = 1;
    }

  switch (contador1) {
    case 0:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      digitalWrite(LED7, LOW);
      digitalWrite(LED8, LOW);
      break;
    case 1:
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      digitalWrite(LED7, LOW);
      digitalWrite(LED8, LOW);
      break;
    case 2:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      digitalWrite(LED7, LOW);
      digitalWrite(LED8, LOW);
      break;
    case 3:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      digitalWrite(LED7, LOW);
      digitalWrite(LED8, LOW);
      break;
    case 4:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      digitalWrite(LED7, LOW);
      digitalWrite(LED8, LOW);
      break;
    case 5:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, LOW);
      digitalWrite(LED7, LOW);
      digitalWrite(LED8, LOW);
      break;
    case 6:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, HIGH);
      digitalWrite(LED7, LOW);
      digitalWrite(LED8, LOW);
      break;
    case 7:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      digitalWrite(LED7, HIGH);
      digitalWrite(LED8, LOW);
      break;
    case 8:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      digitalWrite(LED7, LOW);
      digitalWrite(LED8, HIGH);
      break;
  }

  switch (contador2) {
    case 0:
      digitalWrite(LED9, LOW);
      digitalWrite(LED10, LOW);
      digitalWrite(LED11, LOW);
      digitalWrite(LED12, LOW);
      digitalWrite(LED13, LOW);
      digitalWrite(LED14, LOW);
      digitalWrite(LED15, LOW);
      digitalWrite(LED16, LOW);
      break;
    case 1:
      digitalWrite(LED9, HIGH);
      digitalWrite(LED10, LOW);
      digitalWrite(LED11, LOW);
      digitalWrite(LED12, LOW);
      digitalWrite(LED13, LOW);
      digitalWrite(LED14, LOW);
      digitalWrite(LED15, LOW);
      digitalWrite(LED16, LOW);
      break;
    case 2:
      digitalWrite(LED9, LOW);
      digitalWrite(LED10, HIGH);
      digitalWrite(LED11, LOW);
      digitalWrite(LED12, LOW);
      digitalWrite(LED13, LOW);
      digitalWrite(LED14, LOW);
      digitalWrite(LED15, LOW);
      digitalWrite(LED16, LOW);
      break;
    case 3:
      digitalWrite(LED9, LOW);
      digitalWrite(LED10, LOW);
      digitalWrite(LED11, HIGH);
      digitalWrite(LED12, LOW);
      digitalWrite(LED13, LOW);
      digitalWrite(LED14, LOW);
      digitalWrite(LED15, LOW);
      digitalWrite(LED16, LOW);
      break;
    case 4:
      digitalWrite(LED9, LOW);
      digitalWrite(LED10, LOW);
      digitalWrite(LED11, LOW);
      digitalWrite(LED12, HIGH);
      digitalWrite(LED13, LOW);
      digitalWrite(LED14, LOW);
      digitalWrite(LED15, LOW);
      digitalWrite(LED16, LOW);
      break;
    case 5:
      digitalWrite(LED9, LOW);
      digitalWrite(LED10, LOW);
      digitalWrite(LED11, LOW);
      digitalWrite(LED12, LOW);
      digitalWrite(LED13, HIGH);
      digitalWrite(LED14, LOW);
      digitalWrite(LED15, LOW);
      digitalWrite(LED16, LOW);
      break;
    case 6:
      digitalWrite(LED9, LOW);
      digitalWrite(LED10, LOW);
      digitalWrite(LED11, LOW);
      digitalWrite(LED12, LOW);
      digitalWrite(LED13, LOW);
      digitalWrite(LED14, HIGH);
      digitalWrite(LED15, LOW);
      digitalWrite(LED16, LOW);
      break;
    case 7:
      digitalWrite(LED9, LOW);
      digitalWrite(LED10, LOW);
      digitalWrite(LED11, LOW);
      digitalWrite(LED12, LOW);
      digitalWrite(LED13, LOW);
      digitalWrite(LED14, LOW);
      digitalWrite(LED15, HIGH);
      digitalWrite(LED16, LOW);
      break;
    case 8:
      digitalWrite(LED9, LOW);
      digitalWrite(LED10, LOW);
      digitalWrite(LED11, LOW);
      digitalWrite(LED12, LOW);
      digitalWrite(LED13, LOW);
      digitalWrite(LED14, LOW);
      digitalWrite(LED15, LOW);
      digitalWrite(LED16, HIGH);
      break;
  }

}