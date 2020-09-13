import RPi.GPIO as GPIO
import os, time

GPIO.setmode(GPIO.BCM)
# GPIO19 : reset button
#GPIO.setup(19, GPIO.IN, pull_up_down = GPIO.PUD_UP)
# GPIO26 : shutdown button
GPIO.setup(10,GPIO.OUT)

def shutdown():
  os.system("sudo shutdown -f now")
while 1:
#def reboot(channel):
#os.system("sudo reboot")
  if GPIO.input(10)==GPIO.HIGH:
    shutdown()
#GPIO.add_event_detect(10, GPIO.FALLING, callback = shutdown, bouncetime = 2000)
#GPIO.add_event_detect(19, GPIO.FALLING, callback = reboot, bouncetime = 2000)


