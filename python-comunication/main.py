import serial
import time

try:
    arduino = serial.Serial('COM6', 115200, timeout=1)
    time.sleep(2) # Espera o ESP32 reiniciar após a conexão

    while True:
        command = input('Escreva um comando: ')

        if command.lower() == 'exit':
            print("Saindo do programa.")
            break

        arduino.write(command.encode())

        response = arduino.readline().decode('utf-8').strip()
        print(f'Resposta do ESP32 {response}')
except serial.SerialException as e:
    arduino.close()
    print(f"Erro: {e}")
