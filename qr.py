import subprocess, threading
import picamera
import RPi.GPIO as GPIO
import time
import json
import urllib2

# Port
buzzer = 22
red = 23
green = 24
blue = 25

class Command(object):
    def __init__(self, cmd):
        self.cmd = cmd
        self.process = None

    def run(self, timeout):
        def target():
            print 'Thread started'
            self.process = subprocess.Popen(self.cmd, shell=True, stdout=subprocess.PIPE)
            self.out, self.err = self.process.communicate()
            # print("OUTPUT : " + self.out[8:])
            print 'Thread finished'

        thread = threading.Thread(target=target)
        thread.start()

        thread.join(timeout)
        if thread.is_alive():
            print 'Terminating process'
            self.process.terminate()
            thread.join()
 
        if int(self.process.returncode) == 0 : 
            #req = urllib2.Request("??")
            #response = urllib2.urlopen(req, self.out)
            #jsonData = json.loads(response)
            GPIO.output(blue, True)
            time.sleep(1)
            GPIO.output(blue, False)
            print self.out[8:]

# GPIO Setup
GPIO.setmode(GPIO.BCM)
GPIO.setup(red, GPIO.OUT)
GPIO.setup(green, GPIO.OUT)
GPIO.setup(blue, GPIO.OUT)
GPIO.setup(buzzer, GPIO.OUT)


while True :
	with picamera.PiCamera() as camera :
		camera.capture("image.png")
		camera.close()	
	command = Command("zbarimg image.png")
	command.run(timeout=1)
