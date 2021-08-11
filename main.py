import serial
import time
import speech_recognition as sr

arduino=serial.Serial('/dev/ttyACM0', 9600)
time.sleep(1)

def ouvir_microfone():
    #Habilita o microfone do usuário
    microfone = sr.Recognizer()
    

    #usando o microfone
    with sr.Microphone() as source:
        
        #Chama um algoritmo de reducao de ruidos no som
        microfone.adjust_for_ambient_noise(source)
        
        #Frase para o usuario dizer algo
        print("Diga alguma coisa: ")
        
        #Armazena o que foi dito numa variavel
        audio = microfone.listen(source)
    try:
        
        #Passa a variável para o algoritmo reconhecedor de padroes
        frase = microfone.recognize_google(audio,language='pt-BR')

        #Retorna a frase pronunciada
        print("Você disse: " + frase)
        arduino.write(frase.encode('utf-8'))
        
    #Se nao reconheceu o padrao de fala, exibe a mensagem
    except sr.UnkownValueError:
        print("Não entendi")
        arduino.write(b'erro')
    return frase

while True:
    ouvir_microfone()