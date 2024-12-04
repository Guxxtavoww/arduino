from serial import Serial, SerialException
import time
from tabulate import tabulate
from serial.tools import list_ports

def get_serial_port() -> str | None:
    ports = list_ports.comports()
    available_ports = [(i + 1, port.device, port.description) for i, port in enumerate(ports)]

    if not available_ports:
        print("Nenhuma porta serial disponível.")
        return None

    if len(available_ports) == 1:
        port = available_ports[0][1]
        print(f"Conectando à única porta disponível: {port}")
        return port

    # Print the available ports in a table format
    headers = ["#", "Porta", "Descrição"]
    print(tabulate(available_ports, headers=headers, tablefmt="grid"))

    port_index = int(input("Escolha a porta (número): ")) - 1
    return available_ports[port_index][1]

try:
    port = get_serial_port()

    if port is None:
        exit()

    arduino = Serial(port, 115200, timeout=1)
    time.sleep(1) # Espera o ESP32 reiniciar após a conexão

    while True:
        command = input('Escreva um comando: ')

        if command.lower() == 'exit':
            print("Saindo do programa.")
            break

        arduino.write(command.encode())

        response = arduino.readline().decode('utf-8', errors='ignore').strip()
        print(f'Resposta do ESP32 {response}')
except SerialException as e:
    if 'arduino' in locals():
        arduino.close()
    print(f"Erro: {e}")
