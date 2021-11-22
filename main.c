/* ========================================
 *
 * Copyright Universidad Distrital Francisco José de Caldas, 2021
 * All Rights Reserved
 * Ingeniería en Control y Automatización 
Integrantes
- Juan David Mazorca Espitia
- César Camilo Alonso Castro
- Luis Fernando Garcia 
 *
 * ========================================
*/

#include "project.h"
#include <stdio.h> // libreria para manejar los sprintf 

// Declaración de variables
int dere = 0;
int izq = 0;

// Interrupciones
CY_ISR(DerechaInt){
    if(dere == 0){
        izq = 1;
    }
    if(dere == 1){
        izq = 0;
    }
}

int main(void)
{   
    int32 output;
    char8 str[12];
    float ADCVoltaje;
    CyGlobalIntEnable; // Habilita las interrupciones globales
    
    
    isrDerecha_StartEx(DerechaInt); // Inicia las interrupciones
    Clock_1_Start(); // Inicia el reloj
    PWM_Start(); // Inicial el PWM
    I2C_Start(); // Inicial el modulo I2C
    LCD_I2C_start(); // Inicia el modulo de la LCD con I2C
    
    LCD_I2C_setCursor(0,1); // Columna x Fila
    LCD_I2C_print("Voltaje");

    ADC_Start(); //inicialización de el bloque ADC
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    
    for(;;)
    {
        output=ADC_GetResult32();
        ADCVoltaje=(5.000000/1048576)*output; // (5v*2^20 bits)/valor potenciometro
        LCD_I2C_setCursor(9,1);
        sprintf(str,"%.2f",ADCVoltaje); // Float a String
        LCD_I2C_print(str);
        if(izq ==1){ // Giro del motor a la izquierda
           
            LED_Write(0);
            
            dere=1; // estado del motor
       
            if(ADCVoltaje < 0.5){
                PWM_WriteCompare1(25);
                PWM_WriteCompare2(0);
                LCD_I2C_setCursor(0,0);
                LCD_I2C_print("Velocidad: 10 %");
            }
            if(ADCVoltaje >= 0.5 && ADCVoltaje < 1){
                PWM_WriteCompare1(51);
                PWM_WriteCompare2(0);
                LCD_I2C_setCursor(0,0);
                LCD_I2C_print("Velocidad: 20 %");
            }
            if(ADCVoltaje >= 1 && ADCVoltaje < 1.5){
                PWM_WriteCompare1(76);
                PWM_WriteCompare2(0);
                LCD_I2C_setCursor(0,0);
                LCD_I2C_print("Velocidad: 30 %");
            }
            if(ADCVoltaje >= 1.5 && ADCVoltaje < 2){
                PWM_WriteCompare1(102);
                PWM_WriteCompare2(0);
                LCD_I2C_setCursor(0,0);
                LCD_I2C_print("Velocidad: 40 %");
            }
            if(ADCVoltaje >= 2 && ADCVoltaje < 2.5){
                PWM_WriteCompare1(127);
                PWM_WriteCompare2(0);
                LCD_I2C_setCursor(0,0);
                LCD_I2C_print("Velocidad: 50 %");
            }
            if(ADCVoltaje >= 2.5 && ADCVoltaje < 3){
                PWM_WriteCompare1(135);
                PWM_WriteCompare2(0);
                LCD_I2C_setCursor(0,0);
                LCD_I2C_print("Velocidad: 60 %");
            }
            if(ADCVoltaje >= 3 && ADCVoltaje < 3.5){
                PWM_WriteCompare1(178);
                PWM_WriteCompare2(0);
                LCD_I2C_setCursor(0,0);
                LCD_I2C_print("Velocidad: 70 %");
            }
            if(ADCVoltaje >= 3.5 && ADCVoltaje < 4){
                PWM_WriteCompare1(204);
                PWM_WriteCompare2(0);
                LCD_I2C_setCursor(0,0);
                LCD_I2C_print("Velocidad: 80 %");
            }
            if(ADCVoltaje >= 4 && ADCVoltaje < 4.5){
                PWM_WriteCompare1(229);
                PWM_WriteCompare2(0);
                LCD_I2C_setCursor(0,0);
                LCD_I2C_print("Velocidad: 90 %");
            }
            if(ADCVoltaje >= 4.5 ){
                PWM_WriteCompare1(255);
                PWM_WriteCompare2(0);
                LCD_I2C_setCursor(0,0);
                LCD_I2C_print("Velocidad: 100%");
                
            }            
        }
        if(izq ==0){ // Giro del motor a la derecha
            
           LED_Write(1); 
        
           dere=0;

        
           if(ADCVoltaje < 0.5){
                PWM_WriteCompare2(25);
                PWM_WriteCompare1(0);
                LCD_I2C_setCursor(0,0);
                LCD_I2C_print("Velocidad: 10 %");
            }
            if(ADCVoltaje >= 0.5 && ADCVoltaje < 1){
                PWM_WriteCompare2(51);
                PWM_WriteCompare1(0);
                LCD_I2C_setCursor(0,0);
                LCD_I2C_print("Velocidad: 20 %");
            }
            if(ADCVoltaje >= 1 && ADCVoltaje < 1.5){
                PWM_WriteCompare2(76);
                PWM_WriteCompare1(0);
                LCD_I2C_setCursor(0,0);
                LCD_I2C_print("Velocidad: 30 %");
            }
            if(ADCVoltaje >= 1.5 && ADCVoltaje < 2){
                PWM_WriteCompare2(102);
                PWM_WriteCompare1(0);
                LCD_I2C_setCursor(0,0);
                LCD_I2C_print("Velocidad: 40 %");
            }
            if(ADCVoltaje >= 2 && ADCVoltaje < 2.5){
                PWM_WriteCompare2(127);
                PWM_WriteCompare1(0);
                LCD_I2C_setCursor(0,0);
                LCD_I2C_print("Velocidad: 50 %");
            }
            if(ADCVoltaje >= 2.5 && ADCVoltaje < 3){
                PWM_WriteCompare2(135);
                PWM_WriteCompare1(0);
                LCD_I2C_setCursor(0,0);
                LCD_I2C_print("Velocidad: 60 %");
            }
            if(ADCVoltaje >= 3 && ADCVoltaje < 3.5){
                PWM_WriteCompare2(178);
                PWM_WriteCompare1(0);
                LCD_I2C_setCursor(0,0);
                LCD_I2C_print("Velocidad: 70 %");
            }
            if(ADCVoltaje >= 3.5 && ADCVoltaje < 4){
                PWM_WriteCompare2(204);
                PWM_WriteCompare1(0);
                LCD_I2C_setCursor(0,0);
                LCD_I2C_print("Velocidad: 80 %");
            }
            if(ADCVoltaje >= 4 && ADCVoltaje < 4.5){
                PWM_WriteCompare2(229);
                PWM_WriteCompare1(0);
                LCD_I2C_setCursor(0,0);
                LCD_I2C_print("Velocidad: 90 %");
            }
            if(ADCVoltaje >= 4.5 ){
                PWM_WriteCompare2(255);
                PWM_WriteCompare1(0);
                LCD_I2C_setCursor(0,0);
                LCD_I2C_print("Velocidad: 100%");
                
            }
        }
    }
    
}
