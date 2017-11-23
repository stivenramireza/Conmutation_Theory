import sys
import RPi.GPIO as GPIO
import urllib2
import serial
import subprocess
import requests
import time

arduino = serial.Serial("/dev/ttyACM0", 9600, timeout=1)
api_url = 'https://api.thingspeak.com'
update_key = 'FAWPS66P1MC5VC9Y'
talkback_key = 'KLT3FI87ARIIAXV4'
update_url = api_url + '/update?api_key=' + update_key
talkback_url = api_url + '/talkbacks/20308'
GPIO.setwarnings(False)

def getTemperatura(c):
    T = c.replace('\n','')
    print "Temperatura: %s" % T
    f = urllib2.urlopen(update_url + "&field1=%s" % T)
    print "-> Se envio la temperatura a ThingSpeak"
    f.close()

def getHumedad(h):
    H = h.replace('\r\n','')
    print "Humedad: %s" % H
    f = urllib2.urlopen(update_url + "&field2=%s" % H)
    print "-> Se envio la humedad a ThingSpeak"
    f.close()

def regarDefault():
    r = "100"
    R = r.replace('\r\n','')
    print "Se esta regando las plantas"
    f = urllib2.urlopen(update_url + "&field3=%s" % R)
    print "-> Se envio el mensaje a ThingSpeak"
    f.close()

def regarAutomatico():
    print "Se esta regando las plantas AUTOMATICAMENTE"
    f = urllib2.urlopen(update_url + "&field4=%s" % ra.rstrip('\n'))
    print "-> Se envio el mensaje a ThingSpeak"
    f.close()

def regarManual():
    print "Se esta regando las plantas MANUALMENTE"
    f = urllib2.urlopen(update_url + "&field5=%s" % rm.rstrip('\n'))
    print "-> Se envio el mensaje a ThingSpeak"
    f.close()

def ventilar():
    print "Se esta ventilando"
    f = urllib2.urlopen(update_url + "&field6=%s" % v.rstrip('\n'))
    print "-> Se envio el ventilador a ThingSpeak"
    f.close()

def encenderBombillo():
    print "Se encendio el bombillo"
    f = urllib2.urlopen(update_url + "&field7=%s" % v.rstrip('\n'))
    print "-> Se envio el encendido de bombillo a ThingSpeak"
    f.close()

def main():
        c = arduino.read()
        print c
        if not c:
            cont = urllib2.urlopen("%s/commands/execute?api_key=%s"%(talkback_url, talkback_key))
            command = cont.read()
            if command == 'manual':
                arduino.write('M')
                print "-> Ingreso a la raspberry MANUAL"
                regarManual()
            elif command == 'automatico':
                arduino.write('A')
                print "-> Ingreso a la raspberry AUTOMATICO"
                regarAutomatico()
        elif c == 'T':
            t = arduino.readline()
            getTemperatura(t)
        elif c == 'H':
            h = arduino.readline()
            getHumedad(h)
        elif c == 'R':
            regarDefault()
        elif c == 'A':
            regarAutomatico()
        elif c == 'M':
            regarManual()
        elif c == 'V':
            ventilar()
        elif c == 'E':
            encenderBombillo()

if __name__ == '__main__':
    while(True):
        try:
            print "Obteniendo los valores del arduino..."
            main()
        except:
            print "-> No se obtuvo los valores del arduino"
            arduino.close()
            sys.exit(1)