/* Carro Inalambrico Bluetooth
Dibujo de las conexiones en www.elprofegarcia.com

ARDUINO   L293D(Puente H)        
  5          10
  6          15
  9          7
  10         2
  5V         1, 9, 16
  GND        4, 5, 12, 13
  
  El motor 1 se conecta a los pines 3 y 6 del Puente H
  El motor 2 se conecta a los pines 11 y 14 del Puente H
  
  La fuente de alimentacion de los Motores se conecta a tierra y
  el positivo al pin 8 del puennte H. 
 
Conexion del Modulo Bluetooth HC-06 y el Arduino
ARDUINO    Bluetooth HC-06 
 0 (RX)       TX
 1 (TX)       RX
 5V           VCC
 GND          GND
!!Cuidado!! Las conexiones de TX y RX al modulo Bluetooth deben estar desconectadas
en el momento que se realiza la carga del codigo (Sketch) al Arduino.

*/
int izqA = 5; 
int izqB = 6; 
int derA = 9; 
int derB = 10; 
int vel = 255;            // Velocidad de los motores (0-255)
int estado = 'g';         // inicia detenido

void setup()  { 
  Serial.begin(9600);    // inicia el puerto serial para comunicacion con el Bluetooth
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
 } 
 
void loop()  { 
  
  if(Serial.available()>0){        // lee el bluetooth y almacena en estado
      estado = Serial.read();
  }
  if(estado=='a'){           // Boton desplazar al Frente
      analogWrite(derB, 0);     
      analogWrite(izqB, 0); 
      analogWrite(derA, vel);  
      analogWrite(izqA, vel);       
  }
  if(estado=='b'){          // Boton IZQ 
      analogWrite(derB, 0);     
      analogWrite(izqB, 0); 
      analogWrite(derA, 0);  
      analogWrite(izqA, vel);      
  }
  if(estado=='c'){         // Boton Parar
      analogWrite(derB, 0);     
      analogWrite(izqB, 0); 
      analogWrite(derA, 0);    
      analogWrite(izqA, 0); 
  }
  if(estado=='d'){          // Boton DER
       analogWrite(derB, 0);     
       analogWrite(izqB, 0);
       analogWrite(izqA, 0);
       analogWrite(derA, vel);  
  } 
  
  if(estado=='e'){          // Boton Reversa
       analogWrite(derA, 0);    
       analogWrite(izqA, 0);
       analogWrite(derB, vel);  
       analogWrite(izqB, vel);      
  }
  if (estado =='f'){          // Boton ON se mueve sensando distancia 
 
  }
  if  (estado=='g'){          // Boton OFF, detiene los motores no hace nada 
  }
}
