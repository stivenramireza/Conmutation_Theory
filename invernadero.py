import sys
import RPi.GPIO as GPIO
import urllib2
import serial
import subprocess
import requests
import time

arduino = serial.Serial("/dev/ttyACM0", 9600)
api_url = 'https://api.thingspeak.com'
update_key = 'FAWPS66P1MC5VC9Y'
talkback_key = 'KLT3FI87ARIIAXV4'
update_url = api_url + '/update?api_key=' + update_key
talkback_url = api_url + '/talkbacks/20308'
GPIO.setwarnings(False)

def getTemperatura(c):
    T = c.replace('\n','')
    H = c.replace('\n','')
    print "Temperatura: %s" % T
    print "Humedad: %s" % H
    f = urllib2.urlopen(update_url + "&field1=%s&field2=%s" % (T,H))
    print "-> Se envio la temperatura y la humedad a ThingSpeak"
    f.close()

def getHumedad(h):
    print "Humedad: %s" % h.rstrip('\n')
    f = urllib2.urlopen(update_url + "&field2=%s" % h.rstrip('\n'))
    print "-> Se envio la humedad a ThingSpeak"
    f.close()

def regarDefault(r):
    print "Se esta regando las plantas"
    f = urllib2.urlopen(update_url + "&field3=%s" % r.rstrip('\n'))
    print "-> Se envio el mensaje a ThingSpeak"
    f.close()

def regarAutomatico(ra):
    print "Se esta regando las plantas AUTOMATICAMENTE"
    f = urllib2.urlopen(update_url + "&field4=%s" % ra.rstrip('\n'))
    print "-> Se envio el mensaje a ThingSpeak"
    f.close()

def regarManual(rm):
    print "Se esta regando las plantas MANUALMENTE"
    f = urllib2.urlopen(update_url + "&field5=%s" % rm.rstrip('\n'))
    print "-> Se envio el mensaje a ThingSpeak"
    f.close()

def ventilar(v):
    print "Se esta ventilando"
    f = urllib2.urlopen(update_url + "&field6=%s" % v.rstrip('\n'))
    print "-> Se envio el ventilador a ThingSpeak"
    f.close()

def main():
    while True:
        c = arduino.read(1)
        if not c:
            cont = urllib2.urlopen("%s/commands/execute?api_key=%s"%(talkback_url, talkback_key))
            command = cont.read()
            if command == 'Manual':
                print "Ingreso a la raspberry MANUAL"
                arduino.write('M')
                print "Ingreso a la raspberry AUTOMATICO"
            elif command == 'Automatico':
                arduino.write('A')
        elif c == 'T':
            t = arduino.readline()
            getTemperatura(t)
        elif c == 'H':
            h = arduino.readline()
            getHumedad(h)
        elif c == 'R':
            r = arduino.readline()
            regarDefault(r)
        elif c == 'A':
            ra = arduino.readline()
            regarAutomatico(ra)
        elif c == 'M':
            rm = arduino.readline()
            regarManual(rm)
        elif c == 'V':
            v = arduino.readline()
            ventilar(v)

if __name__ == '__main__':
    while(True):
        try:
            print "Obteniendo los valores del arduino"
            main()
        except:
            print "No se obtuvo los valores del arduino"
            arduino.close()
            sys.exit(1)
