#define A_1 2
#define B_1 3
#define C_1 4
#define D_1 5 
#define E_1 6
#define F_1 7
#define G_1 8

#define A_2 9
#define B_2 10
#define C_2 11
#define D_2 12
#define E_2 13
#define F_2 A0
#define G_2 A1

#define botonPin A2
#define buzzer A3

int Display1[]   = {A_1 , B_1 , C_1 , D_1 , E_1 , F_1 , G_1};
int Display2[]   = {A_2 , B_2 , C_2 , D_2 , E_2 , F_2 , G_2};

bool lanzamientoEnProceso = false;

//	pines[]	      A   B   C   D   E   F   G
int numCERO[]  = {1 , 1 , 1 , 1 , 1 , 0 , 1 };
int numUNO[]   = {0 , 1 , 1 , 0 , 0 , 0 , 0 };
int numDOS[]   = {1 , 1 , 0 , 1 , 1 , 0 , 1 };
int numTRES[]  = {1 , 1 , 1 , 1 , 0 , 0 , 1 };
int numCUATRO[]= {0 , 1 , 1 , 0 , 0 , 1 , 1 };
int numCINCO[] = {1 , 0 , 1 , 1 , 0 , 1 , 1 };
int numSEIS[]  = {1 , 0 , 1 , 1 , 1 , 1 , 1 };
int* numeros[] = {numCERO,numUNO,numDOS,numTRES,numCUATRO,numCINCO,numSEIS};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(Display1[i], 1);
    pinMode(Display2[i], 1);
  }
  pinMode(botonPin, INPUT_PULLUP);
  pinMode(buzzer, 1 );
  Serial.begin(9600);
}

void loop() {
  while (digitalRead(botonPin) == HIGH) {
  }

  if (!lanzamientoEnProceso) {
    lanzarDados();
    lanzamientoEnProceso = true;
  }

  while (digitalRead(botonPin) == LOW) {
  };

  lanzamientoEnProceso = false;
}

void lanzarDados() {
  int resultado1 = random(1, 7);
  int resultado2 = random(1, 7);
  for( int i=0; i<7 ; i++ ){      
      digitalWrite( Display1[i] , numeros[resultado1][i] );
      digitalWrite( Display2[i] , numeros[resultado2][i] );
  } 
  Serial.print("Dado 1: ");
  Serial.println(resultado1);
  Serial.print("Dado 2: ");
  Serial.println(resultado2);
  int sumaR = resultado1 + resultado2;
  if(sumaR == 7){
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
  }
  delay(2000);

  apagarDisplays();
}
void apagarDisplays() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(Display1[i], LOW);
    digitalWrite(Display2[i], LOW);
  }
}