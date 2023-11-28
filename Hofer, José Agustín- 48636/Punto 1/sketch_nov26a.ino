/*trabajo practico en tinkercad: https://www.tinkercad.com/things/9IFDBjOzT9X-ingenious-tumelo*/

const int PULSADOR1 = 2; // Pin del PULSADOR1
const int PULSADOR2 = 3; // Pin del PULSADOR2
const int PULSADOR3 = 4; // Pin del PULSADOR3
const int LED1 = 9;     // Pin del LED1
const int LED2 = 10;    // Pin del LED2

int brilloLED1 = 0;
int brilloLED2 = 0;
int ledSeleccionado = LED1;

void setup() {
  pinMode(PULSADOR1, INPUT_PULLUP);
  pinMode(PULSADOR2, INPUT_PULLUP);
  pinMode(PULSADOR3, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  // Verificar si el PULSADOR1 ha sido presionado
  if (digitalRead(PULSADOR1) == LOW) {
    if (ledSeleccionado == LED1) {
      // Incrementar el brillo del LED1
      brilloLED1++;
      if (brilloLED1 > 255) {
        brilloLED1 = 255;
      } 
      analogWrite(LED1, brilloLED1);
    }

    if(ledSeleccionado == LED2){
        	brilloLED2++;
        	if(brilloLED2 < 255){
        		brilloLED2 = 255;
        	}
      analogWrite(LED2, brilloLED2);
      }
    }//pulsador 1 
 

  // Verificar si el PULSADOR2 ha sido presionado
  if (digitalRead(PULSADOR2) == LOW) {
    if (ledSeleccionado == LED1) {
      // Decrementar el brillo del LED1
      
      if (brilloLED1 < 0) {
        brilloLED1 = 0;
      }else brilloLED1--;
      
      analogWrite(LED1, brilloLED1);
    }
   	if(ledSeleccionado == LED2){
        	if(brilloLED2 < 0){
        		brilloLED2 = 0;
        	}else brilloLED2--;
        	
      analogWrite(LED2, brilloLED2);
      }
    }//pulsador2

  // Verificar si el PULSADOR3 ha sido presionado
  if (digitalRead(PULSADOR3) == LOW) {
    // Cambiar el LED seleccionado
    if (ledSeleccionado == LED1) {
      ledSeleccionado = LED2;
      analogWrite(LED1, 0); // Apagar LED1
       brilloLED1 = 0;
      delay(100);
    
    } else { // si led2 esta seleccionado
      ledSeleccionado = LED1;
      analogWrite(LED2, 0); // Apagar LED2
       brilloLED2 = 0;
      delay(100);
      
    }
  }// pulsador3
  
}// loop
