from time import sleep
from playsound import playsound
import serial


def main():
 serial_inst = serial.Serial('COM3', baudrate=9600, timeout=1)
 while True:
  try:
   msg = int(serial_inst.readline().decode('ascii'))
   if msg == 1:
    playsound('Audio file')
    sleep(10)
   sleep(1)
  except Exception as e:
   print(e)
   sleep(10)

if __name__ == '__main__':
    main()
