//
//  main.c
//  Exe12.26
//
//  Created by Francesco Parrucci on 05/08/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
// 
//  SEZIONE SPECIALE: COSTRUITE IL VOSTRO COMPILATORE
//
//  (Il linguaggio semplice) Prima di cominciare a costruire il complitare, discuteremo un semplice ma potente linguaggio di alto livello simile alle prime versioni
//  del popolare linguaggio BASIC. Chiameremo questo linguaggio Semplice. Ogni costrutto eseguibile di Semplice sarà formato da un numero di riga e da questo 
//  linguaggio Semplice. I numeri di riga dovranno comparire in ordine crescente. Ogni istruzione incomincierà con uno dei seguenti comandi di Semplice:
//  rem , input, let, print, goto, if/goto o end (Consultate la Figura 12.23). Eccettuato end, tutti i comandi potranno essere usati ripetutamente. Semplice valuterà
//  soltanto delle espressioni intere usando gli operatori  + , - , * e /. Questi operatori manterranno la stessa priorità che hanno in C. Potranno comunque essere 
//  utilizzate delle parentesi per cambiare l'ordine di valutazione di un'espressione.
//  Il nosttro compilatore di Semplice riconoscerà soltanto le lettere minuscole. Tutti i caratteri inclusi in un file di Semplice dovranno essere in minuscolo (quelli
//  maiuscoli provocheranno un errore di sintassi, sempre che non compaiano in un'istruzione rem, nel qual caso saranno ignorati). I nomi di variabile saranno formati
//  da una singola lettera. Il Semplice non consentirà nomi di variabile descrittivi, perciò queste dovranno essere descritte nei commenti in modo da indicare il loro
//  uso all'interno del programma. 
//  Il Semplice userà soltanto delle variabili intere e non sarà necessario dichiararle: basterà menzionare all'interno del programma un nome di variabile, perchè 
//  questa sia automaticamente dichiarata e inizializzata a zero. La sintassi di Semplice non consentirà la manipolaizone delle stringhe (lettura, scrittura, confronto
//  ecc.). Il compilatore genererà un errore di sintassi, qualora incontri all'interno di un programma in linguaggio Semplice una stringa preceduta da un comando 
//  diverso da rem. Il nostro compilatore presumerà che i programmi in linguaggio Semplice siano stati immessi correttamente. L'Esercizio 12.29 chiederà al lettore di
//  modificare il compilatore cosi che possa eseguire la verifica della sintassi.
//  	Semplice userà l'istruizone condizionale if/goto  e quella incondizionata goto per alterare il flusso di controllo durante l'esecuzione del programma.
//  Qualora l'istruzione if/goto saranno validi il controllo sarà trasferito a una riga specifica del programma. In una istruzione if/goto saranno validi i seguenti
//  operatori relazionali e di uguaglianza : <, >, <=, >= , == o !=. La priorità di questi operatori sarà la stessa che hanno in C.
//
//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
//  Comando 	Istruzione di esempio				Descrizione
//  
//  rem		50 rem questo è un commento			Qualsiasi testo successivo al comando rem sarà inserito soltanto a scopo docuemntativo e sarà ignorato
//  								dal compilatore.
//
//  input 	30 input x					Visualizzerà un punto interrogativo per chiedere all'utente di immettere un intero. Leggerà l'intero 
//  								dalla tastiera e lo immagazzinerà in x.
//
//  let 	80 let u = 4 * (j - 56)				Assegnerà a u il valore 4 * (j - 56). Notate che, a destra del segno di uguale, potrebbe comparire un'
//  								espressione arbitrariamente complessa.
//
//  print 	10 print w					Visualizzerà il valore di w.
//
//  goto 	70 goto 45 					Trasferirà il controllo del programma alla riga 45.
//
//  if/goto 	35 if i == z goto 80				Confronterà i e z per verificarne l'uguaglianza  e trasferirà il controllo del programma alla riga 80
//  								, qualora la condizione risulti verà; in caso contrario, continuerà l'esecuzione con l'istruzione
//  								successiva.
//
//  end 	99 end						Terminerà l'esecuzione del programma.
//
//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
//  Prendiamo ora in considerazione alcuni programmi scritti in linguaggio Semplice che dimostreranno le caratteristiche di quest'ultimo. Il primo programma (Figura 12.
//  24) leggerà due interi dalla tastiera, immagazzinerà i loro valori nelle variabili a e b e calcolerà e visualizzerà la loro somma (immagazzinata nella variabile c).
//
//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
//  10 rem 	determinare e visualizzare la somma di due interi
//  15 rem
//  20 rem	prende in input i due interi
//  30 input a
//  40 input b
//  45 rem
//  50 rem 	somma gli interi e immagazzina il risultato in c
//  60 let c = a + b
//  65 rem
//  70 rem 	visualizza il risultato
//  80 print c
//  90 rem 	termina l'esecuzione del programma
//  99 end
//
//  -----------------------------------------------------------------------------------------------------------------------------------------------------------------
//
//  Figura 12.24 Determinare la somma di due interi.
//
//  Il programma della Figura 12.25 determinerà e visualizzerà il maggiore tra due numeri interi. Gli interi saranno letti dalla tastiera e immagazzinati in s e t.
//  L'istruzione if/goto verificherà la condizione s >= t. Qualora la condizione sia vera, il controllo sarà trasferito alla riga 90 e s sarà visualizzato; altrimenti
//  , verrà visualizzato t e il controllo sarà trasferito all'istruzione end della riga 99, dove il programma terminerà la propria esecuzione.
//  -----------------------------------------------------------------------------------------------------------------------------------------------------------------
//  10 rem determinare il maggiore di due interi
//  20 input s
//  30 input t
//  32 rem
//  35 rem 	verifica se s >= t 
//  40 if s >= t goto 90
//  45 rem 
//  50 rem 	t è maggiore di s, perciò visualizza t
//  60 print t 
//  70 goto 99
//  75 rem
//  80 rem 	s è maggiore o uguale a t, perciò visualizza s
//  90 print s
//  99 end
//  -----------------------------------------------------------------------------------------------------------------------------------------------------------------
//  Figura 12.25 Trovare il maggiore di due interi.
//  Il Semplice non fornisce una struttura di iterazione (come for, while o do/while del C). Tuttavia, può simulare ogni struttura di iterazione del C, usando le istru
//  zioni if/goto e goto. La figura 12.26 userà un ciclo controllato da un valore sentinella per calcolare i quadrati di vari interi. Ogni intero sarà preso in input
//  dalla tastiera e immagazzinato nella variabile j. Qualora il valore immesso corrisponda a quello di guardia -9999, il controllo sarà trasferito alla riga 99  dove
//  l'esecuzione del programma terminerà. In caso contrario, il quadrato di j sarà assegnato a k, questa sarà visualizzata sullo schermo e il controllo sarà passato 
//  alla riga 20, dove sarà preso in input l'intero successivo.
//  Usando come vostra guida i programmi di esempio delle Figure 12.24, 12.25 e 12.26, scrivete un programma in linguaggio Semplice che esegua ognuna delle seguenti
//  attività:
//
//  a) Prendete in input tre interi, determinatene la media e visualizzate il risultato.
//  
//  10 rem Prendete in input tre interi, determinate la media e visualizzate il risultato
//  15 input a
//  20 input b
//  25 input c
//  30 rem Effettua la media
//  35 let d = (a + b + c) / 3
//  40 rem Visualizza il risultato
//  45 print d
//  50 end
//
//  b) Usate un ciclo controllato da un valore sentinella per prendere in input 10 interi e calcolare e visualizzare la loro somma.
//  
//  10 rem Utilizza un ciclo controllato da valore sentinella per prendere in input 10 interi e calcolare e visualizzare la loro somma
//  15 let c = 1
//  20 let a = 0
//  25 input b 
//  30 let a = a + b
//  35 let c = c + 1
//  40 if c < 10 goto 20
//  45 print a 
//  50 end
//  
//  c) Usate un ciclo controllato da un contatore per prendere in input 7 interi, alcuni positivi e altri negativi, e calcolare e visualizzare la loro media.
//
//  10 Utilizza un ciclo controllato da un contatore per prendere in input 7 interi e visualizzarne la media
//  15 let c = 1
//  20 let a = 0
//  25 input b
//  30 let a = a + b
//  35 let c = c + 1
//  40 if c < 7 goto 25
//  45 let a = a / c
//  50 print a
//  50 end 
//
//  d) Prendete in input una serie di interi e determinatene e visualizzatene il maggiore. Il primo intero in input indicherà quanti numeri dovranno essere elaborati.
//  
//  10 rem Prendete in input una serie di interi e determinare e visualizzare il maggiore. Il primo intero in input indicherà quanti numeri dovranno essere elaborati
//  15 rem 
//  20 rem Prende in input il primo valore che corrisponde anche al valore sentinella
//  25 input a
//  30 rem Passaggio del primo valore nelle variabili temporanee
//  35 let c = a
//  40 let b = c 
//  45 rem
//  50 rem Prende in input il valore successivo da confrontare
//  55 input c
//  60 let a = a - 1
//  65 rem Se l'ultimo valore acquisito è maggiore del precedente memorizzalo nel precedente istruzione 40
//  70 if c > b goto 40
//  75 rem Altrimenti decrementi a e se è uguale a zero termini altrimenti prendi un successivo numero istruzione 55
//  80 if a > 1 goto 55
//  85 print b
//  90 end 
//  
//  e) Prendete in input 10 interi e visualizzatene il minore.
//  
//  10 rem Prendete in input 10 interi e visualizzatene il minore
//  15 rem Imposto il valore sentinella
//  20 let a = 10
//  25 rem Prende in input il primo intero lo memorizza in b ed è quello che dovrà risultare il minore
//  35 input b
//  40 goto 60
//  45 rem Imposto c uguale b 
//  50 let b = c
//  55 rem Prendo in input il secondo intero e lo posiziono in b
//  60 input c
//  65 let a = a - 1
//  70 if b > c goto 50  
//  65 if a > 1 goto 60 
//  70 print b
//  75 end
//
//
//  f) Calcolate e visualizzate la somma degli interi pari compresi tra 2 e 30.
//
//  10 rem Calcolate e visualizzate la somma degli interi pari compresi tra 2 e 30
//  15 rem Inizio da 2
//  20 let a = 2
//  25 rem aggiungo 2
//  30 let a = a + 2
//  35 rem verifico che il valore sia inferiore a 30 
//  40 if a < 30 goto 30
//  45 rem Se il valore di a è arrivato a 30 stampo e termino
//  50 print a
//  55 end
//
//  g) Calcolate e visualizzate il prodotto degli interi dispari compresi tra 1 e 9.
//
//  10 rem Calcolate il prodotto degli interi dispari compresi tra 1 e 9
//  15 rem
//  20 let a = 1
//  25 let b = 1
//  30 let a = a * b
//  35 let b = b + 2
//  40 if b < 10 goto 30
//  45 print a
//  50 end
//
