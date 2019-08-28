//
//  main.c
//  Exe12.28
//
//  Created by Francesco Parrucci on 27/08/19.
//  Copyright © 2019 Francesco Parrucci. All rights reserved.
//
//  (Ottimizzate il compilatore di Semplice) Quando un programma sarà compilato e convertito in LMS, sarà generato un insieme di istruzioni. Certe combinazioni di istruzioni si ripeteranno spesso, di solito in triplette dette
//  produzioni. Queste saranno normalmente formate da tre istruzioni come load, add e store. Per esempio, la Figura 12.30 mostra cinque delle istruzioni LMS che sono state generate durante la compilazione del programma nella Figura 
//  12.28. Le prime tre istruzioni corrispondono alla produzione che aggiunge 1 a y. Osservate che le istruzioni 06 e 07 immagazzinano il valore dell'accumulatore nella posizione temporanea 96 e poi lo ricaricano nuovamente nell'
//  accumulatore, in modo che l'istruzione 08 possa immagazzinarlo nella posizione 98. Spesso una produzione è seguita da un'istruzione di caricamento che operano sulla stessa posizione di memoria. L'ottimizzazione consentirà 
//  al Simpletron di eseguire piu velocemente il programma, poichè in questa versione ci saranno meno istruzioni. La Figura 12.31 mostra il codice LMS ottimizzato per il programma della Figura 12.28. Osservate che nel codice 
//  ottimizzato ci sono quattro istruzioni in meno: un risparmio di memoria del 25 %.
//  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  04 + 2098 (load)
//  05 + 3097 (add)
//  06 + 2196 (store)
//
//  07 + 2096 (load)
//  08 + 2198 (store)
//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  Figura 12.30 Codice non ottimizzato tratto dal programma in Figura 12.28
//
//  Modificate il compilatore in modo da offrire un'opzione di ottimizzazione del codice generato in Linguaggio Macchina Simpletron. Confrontate manualmente il codice non ottimizzato e quello ottimizzato e calcolate la percentuale
//  di riduzione.
//  -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  Programma in semplice					Posizione e istruzione in LMS Descrizione
//  -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  5  rem aggiunge 1  a x					nessuna 	rem ignorata
//  10 input x							00 +1099	legge x nella posizione 99
//  15 rem verifica se y == x					nessuna		rem ignorata
//  20 if y == x goto 60					01 + 2098	carica y (98) nell'accumulatore
//  								02 + 3199	sottrae x (99) dall'accumulatore 
//  								03 + 4211	se zero, salta alla posizione 11 
//  25 rem incrementa y						nessuna		rem ignorata
//  30 let y = y + 1						04 + 2098	carica y nell'accumulatore
//  								05 + 3097	aggiunge 1 (97) all'accumulatore
//  								06 + 2198	immagazzina l'accumulatore in y (98)
//  35 rem aggiunge y al totale					nessuna		rem ignorata
//  40 let t = t + y						07 + 2096	carica t dalla locaizone (96)
//  								08 + 3098	aggiunge y (98) all'accumulatore 
//  								09 + 2196 	immagazzina l'accumulatore in t (96)
//  45 rem ciclo y						nessuna		rem ignorata
//  50 goto 20							10 + 4001	salta alla posizione 01
//  55 rem visualizza il risultato 				nessuna		rem ignorata
//  60 print t							11 + 1196	visualizza t (96) sullo schermo
//  99 end							12 + 4300	termina l'esecuzione.
//  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  Figura 12.31 Il codice ottimizzato per il programma della Figura 12.28
//
//
//  
//
//  (Costruite un compilatore; Prerequisiti: completate gli Esercizi 7.18, 7.19, 12.12 , 12.13 e 12.26) Ora che il linguaggio Semplice è stato presentato (Esercizio 12.26), discuteremo di come costruire il nostro compilatore di 
//  Semplice. In primo luogo, considereremo il processo attraverso il quale un programma in linguaggio Semplice sarà convertito  in LMS ed eseguito dal simulatore Simpletron (consultate la Figura 12.27). Un file contenente un 
//  programma in linguaggio semplice sarà letto dal compilatore e convertito in codice LMS. Questo sarà salvato in un file su disco, nel quale le struzioni LMS compariranno una per riga. Il file LMS sarà quindi caricato nel simu
//  latore Sempletron e i risultati saranno inviati a un file su disco e allo schermo. Osservate che il programma Simpletron sviluppato nell'Esercizio 7.19 prendeva il suo input dalla tastiera. Essa dovrà quindi essere modificato
//  per leggere l'input da un file, cosi che possa eseguire i programmi prodotti dal nostro compilatore. 
//  	Per convertirlo in LMS , il compilatore effettuare due passaggi sul programma in linguaggio Semplice. Il primo passaggio costruirà la tabella dei simboli (la tabella dei simboli sarà discussa piu tardi in dettaglio) nella
//  quale saranno immagazzinati, con i loro tipi di dato e le rispettive posizioni all'interno del codice LMS finale, ogni numero di riga, nome di variabile e costante del programma in linguaggio Semplice. Il primo passo produrrà 
//  anche le istruzioni LMS corrispondenti a ogni espressione di Semplice. Come vedremo, il primo pasaggio produrrà un codice LMS che conterrà alcune istruzioni incomplete, qualora il programma in linguaggio Semplice contenga 
//  delle istruzioni che trasferiscano il controllo a una riga successiva del codice. Il secondo passaggio del compilatore individuerà e completerà le istruzioni incomplete e salverà il programma LMS in un file.
//  ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
//  10 rem 	calcolare i quadrati di vari interi
//  20 input j
//  23 rem
//  25 rem 	controlla il valore sentinella
//  30 if j == -9999 goto 99
//  33 rem
//  35 rem 	calcola il quadrato di j e assegna il risultato a k
//  40 let k = j * j
//  50 print k
//  53 rem 
//  55 rem 	itera per prendere il prossimo j
//  60 goto 20 
//  99 end
//  ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  Fig 12.26 Calcolare il quadrato di vari interi
//
//  File Semplice ------->  Compilatore --------> File LMS --------> Simulatore di Simpletron
//									|		|
//									|		|
//									|		|
//									v		v
//								    Output su 	   Output sullo
//							 	    disco	     schermo
//
//  ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  Figura 12.27 Scrivere, compilare ed eseguire un programma in linguaggio Semplice.
//
//  Primo passaggio
//  Il compilatore inizierà leggendo nella memoria un'istruzione del programma in linguaggio Semplice. Per l'elaborazione e la compilazione, la riga dovrà essere separata nei suoi singoli token (ovverosia, nei "pezzi" di un 
//  istruzione) e, per facilitare questo compito, potrà essere usata la funzione strtok della libreria standard. Ricordate che ogni istruzione incomincia con un numero di riga seguito da un comando. Man mano che il compilatore 
//  scomporrà un'istruzione nei suoi token, questi saranno sistemati nella tabella dei simboli, qualora siano dei numeri di riga, delle variabili o delle constanti. Un numero di riga sarà sistemato nella tabella dei simboli 
//  soltanto qualora sia il primo token di un'istruzione. La symolTable è un vettore di strutture tableEntry che rappresenterà ogni simbolo del programma e di conseguenza potrà essere particolarmente corposa per certi programmi. Per
//  ora, create la symbolTable come un vettore di 100 elementi. Potrete incrementare o ridurre le sue dimensioni, una volta che il programma sarà funzionante.
//  ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  La definizione della struttura tableEntry è la seguente:
//
//  struct tableEntry {
//  	int symbol;
//  	char type;	/* 'C' , 'L', o 'V' */
//  	int location;   /* da 00 a 99 */
//  }
//
//  Ogni struttura tableEntry contiene tre membri. Il membro symbol è un intero che conterrà la rappresentazione ASCII di una variabile (ricordate che i nomi di variabile sono caratteri singoli), un numero di riga o una costante.
//  Il membro type corrisponderà a un carattere che indicherà il tipo del simbolo: 'C' per una costante, 'L' per un numero di riga o 'V' per una variabile. Il membro location conterrà la posizione (da 00 a 99) puntata dal simbolo
//  nella memoria del Simpletron. Questa è un vettore di 100 elementi interi in cui saranno immagazzinati i dati e le istruzioni LMS, Per un nu8mero di riaga , la posizione rappresenterà l'elemento nel avettore della memoria del 
//  Simpletron in cui incominceranno le istruzioni LMS corrispondenti a quella in linguaggio Semplice. Per una variabile o una costante la posizione rappresenterà l'elemento nel vettore della memoria del Simpletron in cui sarà 
//  immagazzinata la variabile, o la costante. Queste saranno allocate cominciando dalla fine della memoria del Simpletron. La prima variabile o costante sarà immagazzinata nella posizione 00 , la successiva nella 98, ecc.
//  La tabella dei simboli gioca una parte integrante nella conversione in LMS dei programmi scritti in linguaggio Semplice. Nel Capitolo 7 abbiamo appreso che un'istruzione LMS è un intero di quattro cifre formato da due part
//  il cosidce dell'operazione e l'operando. Il codice dell'operazione è determinato dai comandi del linguaggio Semplice. Per esempio, il comando di Semplice input corrisponde al codice dell'operazione LMS 10 (read), mentre
//  il comando di Semplice print corrisponde al codice dell'operazione LMS 11(write). L'operando è una posizione di memoria contenente i dati su cui il codice dell'operazione dovrà eseguire il proprio compito (il codice dell'
//  operazione 10, per esempio, leggerà un valore dalla tastiera e lo immagazzinerà nella posizione di memoria specificata dall'operando). Per ogni simbolo , il compilatore effettuerà una ricerca nella symbolTable, per determinarne
//  la posizione all'interno della memoria del Simpletron, cosi che la stessa possa essere utilizzata per completare le istruzioni LMS.
//  La compilazione di ogni istruzione di Semplice è basata sui suoi comandi. Per esempio, una volta che il numero di riga di un rem sarà stato inserito nella tabella dei simboli, la parte rimanente dell'istruzione sarà ignorata
//  dal compilatore, poichè un commento ha solo scopi documentativi. Le istruzioni input, print, goto, ed end corrisponderanno a quelle LMS read, write, bach (a una posizione speficata) e halt. Le istruzioni contententi questi
//  comandi di Semplice saranno convertite direttamente in LMS (notate che un goto potrebbe contenere un riferimento irrisolto, qualora il numero di riga punti a un'istruizione successiva nel file del programma in linguaggio 
//  Semplice; ovverosia il cosiddetto riferimento in avanti).
//  Un goto con un riferimento irrisolto sarà compilato in un'istruzione LMS che dovrà essere contrassegnata, per indicare che il secondo passaggio del compilatore dovrà completarla. Le segnalazioni (o flag) saranno immagazzinate
//  nei 100 elementi del vettore flags di tipo int, che saranno inizializzati con il valore -1. Nel caso in cui la posizione di memoria puntata da un numero di riga del programma in lunguaggio Semplice non sia ancora nota 
//  (ovverosia , non sia stata ritrovata nella tabella dei simboli), allora quel numero di riga dovrà essere immagazzinato nell'elemento del vettore flags avente lo stesso indice dell'istruizone incompleta. L'operando dell'
//  istruzione incompleta sarà impostato temporaneamente a 00. Per esempio, un'istruzione di salto incondizionato (che abbia un riferimento in avanti) sarà lasciata come +4000 fino al secondo passaggio del compilatore (che 
//  descriveremo tra breve).
//  La compilazione delle istruzioni if/goto e let è piu complicata di quella delle altre: infatti, queste sono le uniche che producono più di un'istruzione LMS. Per un'struzione if/goto, il compilatore produrrà un codice che 
//  verificherà la condizione e, se sarà necessario, salterà a un'altra riga. Il risultato del salto potrà anche essere un riferimento irrisolto. Ognuno degli operatori relazionali e di uguaglianza potrà essere simulato usando
//  le istruzioni LMS branch zero e branch negative, o eventualmente una combinazione di entrambe.
//  Per un'istruzione let, il compilatore produrrà un codice che valuterà un espressione aritmetica arbitrariamente complessa formata da variabili intere e/o costanti. Le espressioni dovranno separare ogni operando e operatore con
//  degli spazi. Gli Esercizi 12.12 e 12.13 hanno presentato l'algoritmo di conversione dalla notazione infissa a quella polacca inversa, e l'algoritmo di valutazione usato dai compilatorei per valutare le espressioni in notazione
//  polacca inversa. Prima di procedere con il vostro compilatore, dovrete completare ognuno dei suddetti esercizi. Quando un compilatore incontrerà un 'espressione, la convertirà dalla notazione infissa a quella polacca inversa
//  e quindi la valuterà.
//  Ma in che modo il compilatore produrrà il codice per valutare un'espressione che contenga delle variabili? L'algoritmo di valutazione delle espressioni in notazione polacca inversa prevede una variante, che consentirà al nostro
//  compilatore di generare le istruzioni LMS, invece di valutare effettivamente le espressioni. Per attivare la suddetta variante nel compilatore, l'algoritmo di valutazione delle espressioni in notazione polacca inversa dovrà 
//  essere modificato in modo che possa ricercare (ed eventualmente inserire) nella symbolTable ogni simbolo che incontrerà. Per ognuno di quei simboli, l'algoritmo dovrà quindi determinare e inserire nella pila la corrispondente
//  posizione di memoria, invece del simbolo. Nel momento in cui verrà incontrato un operatore all'interno dell'espressione in notazione polacca inversa, saranno estratte le due posizioni di memoria in cima alla pila e sarà 
//  prodotto il codice in linguaggio macchina neccessario per eseguire l'operaizone, usando come operandi le posizioni di memoria. Il risultato di ogni componente dell'espressione sarà immagazzinato in una posizione di memoria
//  temporanea e inserito nuovamente nella pila, perchè possa preseguire la valutazione dell'espressione in notaizone polacca inversa. Nel momento in cui la valutazione sarà stata completata, la posizione di memoria contenente
//  il risultato sarà l'unica posizione rimasta sulla pila. Questa sarà dunque estratta e saranno generate le istruzioni LMS per assegnare il risultato alla variabile a sinistra dell'istruzione let.
//
//  Secondo passaggio
//
//  Il secondo passaggio del compilatore eseguirà due attività: risolvere ogni riferimento irrisolto e salvare il codice LMS in un file. La risoluzione dei riferimenti avverrà nel modo seguente:
//
//  1) Ricercate nel vettore flags un riferimento irrisolto (ovverosia, un elemento con un valore diverso da -1).
//  2) Individuate nel vettore symbolTable la struttura contenente il simbolo immagazzinato in flags (assicuratevi che il tipo del simbolo sia 'L', per i numeri di riga).
//  3) Inserite la posizione di memoria indicata dal membro della struttura location nell'istruzione con il riferimento irrisolto. Ricordatevi che un'istruzione contenente un riferimento irrisolto ha l'operando 00.
//  4) Ripetete i passi 1, 2 e 3 finchè non sarà stata raggiunta la fine del vettore flags.
//
//  Una volta che il processo di risoluzione sarà stato completato, l'intero vettore del codice LMS sarà salvato in un file su disco, sistemando un'istruizone LMS per riga. Questo file potrà esere letto dal Simletron per l'esecu
//  zione, una volta che avrete modificato il simulatore in modo che possa leggere il suo input da file.
//
//  Un esempio completo.
// 
//  L'esempio seguente illustrerà una conversione dompleta in LMS di un programma scritto in linguaggio Semplice, cosi come sarà eseguita dal compilatore di Semplice. Considerate un programma scritto in linguaggio Semplice, che 
//  prenda in input un intero e sommi i valori compresi nell'intervallo da 1 all'intero specificato. Nella Figura 12.28 sono mostrati il programma e le istruzioni LMS generate dal primo passaggio. Nella Figura 12.29 è mostrata
//  la tabella dei simboli costruita dal primo passaggio.
//  La maggior parte delle istruzioni di Semplice potrà essere convertita direttamente in singole istruzioni LMS. In questo programma, led eccezioni saranno rappresentate dai commenti, dall'istruzione if/goto della riga 20 e 
//  dall'istruzione let. I commmenti non si traducono in linguaggio macchina. Tuttavia, i numeri di riga di un commento saranno ugualmente sistemati nella tabella dei simboli, nell'eventualità che siano stati punta da un goto
//  o da un if/goto. La riga 20 specifica che il controllo del programma passerà alla riga 60 qualora la condizione y == x sia vera. Dato che la riga 60 comparirà solo più tardi nel programma, il primo passaggio del compilatore
//  non lo ha ancora sistemato nella tabella dei simboli (i numeri di riga saranno sistemati nella tabella dei simboli, solo qualora compaiano come primo token di un'istruzione). Di conseguenza , a posizione 03 del vettore che 
//  contiene le istruzioni LMS. Il compilatore sistemerà dunque il 60 nella posizione 03 del vettore flags per indicare che il secondo passaggio dovrà completare questa istruzione.
//  ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  Programma in Semplice					Posizione e istruzione LMS Descrizione
//  ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  5 	rem 	aggiunge 1 a x					nessuna 	rem ignorata
//  10  input	x						00 +1099	legge x nella posizione 99
//  15  rem	verifica se y == x				nessuna 	rem ignorata
//  20  if y == x goto 60 					01 +2098	carica y (98) nell'accumulatore
//  								02 +3199	sottrae x  (99) dall'accumulatore
//  								03 +4200	branch zero a una posizione irrisolta
//  25  rem incrementa y					nessuna 	rem ignorata
//  30  let y = y + 1						04 +2098	carica y nell'accumulatore
//  								05 +3097	aggiunge 1 (97) all'accumulaore
//  								06 +2196	lo immagazzina nella posizione temporanea 96
//  								07 +2096	carica dalla posizione temporanea 96
//  								08 +2198	immagazzina l'accumulatore in y
//  35  rem aggiunge y al totale 				nessuna		rem ignorata
//  40  let t = t + y						09 +2095	carica t (95) nell'accumulatore
//  								10 +3098  	aggiunge y all'accumulatore
//  								11 +2194	immagazzina nella posizione temporanea 94
//  								12 +2094	carica dalla posizione temporanea 94
//  								13 +2195	immagazzina l'accumulatore in t
//  45	rem ciclo y 						nessuna		rem ignorata
//  50	goto 20							14 +4001	salta alla posizione 01
//  55	rem  visualizza il risultato				nessuna		rem  ignorata
//  60	print t							15 +1195	visualizza t sullo schermo
//  99	end							16 +4300	termina l'esecuzione
//  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  Figura 12.28 Le istruzioni LMS generate dopo il primo passaggio del compilatore.
//
//  Dovremo mantenere traccia della posizione della prossima istruzione nel vettore LMS, perchè non c'è una corrispondenza uno a uno tra le istruzioni di Semplice e quelle di LMS. Per esempio, l'istruzione if/goto della riga 20 
//  sarà compilata in tre istruzioni LMS. Di conseguenza, ogni volta che sarà generata un'istruzione dovremo incrementare il contatore di istruzioni, in modo che punti alla posizione successiva del vettore LMS. Osservate che la 
//  dimensione delal memoria del Simpletron potrebbe rappresentare un problema per i programmi in linguaggio Semplice formati da mole istruzioni, variabili e costanti. Infatti , è probabile che il compilatore esaurisca la memoria
//  PEr controllare questa eventualità, il vostro programma dobrà contenere un contatore di dati, in modo da conservare la posizione del vettore LMS nella quale sarà immagazzinata la prossima variabile o costante. Il vettore LMS 
//  sarà pieno quando il valore del contatore di istruzioni sarà superiore a quello del contatore di dati. In questo caso, il processo di compilazione dovrà essere interrotto e il compilatore dovrà visualizzare un messaggio di 
//  errore, per indicare che avrà esaurito la memoria durante la compilazione.
//
//  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  Simbolo 		Tipo		Posizione
//  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  5			L		00
//  10			L		00
//  'x'			V		99
//  15			L		01	
//  20			L		01
//  'y'			V		98	
//  25			L		04
//  30			L		04
//  1			C		97
//  35			L		09
//  40			L		09
//  't'			V		95
//  45			L		14
//  50			L		14
//  55			L		15
//  60			L		15
//  99			L		16
//  ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  Figura 12.29 Tabella dei simboli per il programma della Figura 12.28
//
//  Un esame passo per passo del processo di compilazione
//  Osserviamo ora il processo di compilazione per il programma in linguaggi Semplice mostrato nella Figura 12.28. Il compilatore legge in memoria la prima riga del progamma
//
//  5 rem 	aggiunge 1 a x
//
//  Il primo simbolo dell'istruzione, il numero di riga, sarà determinato usando strtok (sonsultate il Capitolo 8 per una discussione sulle funzioni C di manipolazione delle strighe). Il simbolo restituito da strtok sarà convertito
//  in un intero usando atoi, perciò nella tabella dei simboli potrà essere ricercato il token 5 che sarà inserito nella suddetta tabella, qualora non sia stato ritrovato. Dato che siamo all'inizio del programma e che questa è la 
//  prima riga, nella tabella non c'è ancora nessun simbolo. Di conseguenza, il 5 vi sarà inserito come tipo L (numero di riga) e sarà assegnato alla prima posizione (00) deò vettpre LMS. Nonostante si tratti di un commento, allo-
//  cheremo ugualmente uno spazio per il numero di riga all'interno della tabella dei simboli, nell'eventualità che sia stato puntato da un goto o un fi/goto. Per la rem non sarà generata nessuna istruzione LMS e quindi il relativo
//  contatore non sarà invrementato.
//  In seguito, sarà analizzata l'istruzione 
//
//  10 intput x
//
//  Il numero di riga 10 sarà sestemato nella tabella dei simboli, come tipo L, e sarà assegnato alla prima posizine del vettore LMS (00, poichè il programma comincia con un commento e quindi il contatore di istruzioni varrà ancora
//  00). Il comando input indica che il prossimo simbolo sarà una variabile, poichè in un'istruzione input può comparire solo unavariabile. Il compilatore dovrà semplicemente determinare la posizione di x nel vettore LMS, poichè
//  input corrisponde direttamente a un codice di operazione LMS. Il simbolo x non sarà ancora presente nella tabella dei simboli e quindi vi dovrà essere inserita la sua rappresentzione ASCII, con il tipo V, e gli sarà assegnata
//  la posizione 99 del vettore LMS, perchè l'immagazzinamento dei dati incomincia dalla posizione 99 e prosegue dall'alto verso il basso.
//  A questo punto potrà essere generato il codice LMS per questa istruzione. Il codice di operaizone 10 (ovverosia quello LMS per la lettura ) sarà moltiplicato per 100 e la posizione di x, determinata dalla tabella dei simboli,
//  vi sarà aggiunta per completare l'istruzione. L'istruzione sarà quindi immagazzinata nella posizione 00 del vettore LMS. Il contatore di istruzioni sarà incrementato di 1 poichè sarà stata generata una sola istruzione LMS.
//  In seguito sarà analizzata l'istruzione 
//
//  15 rem verifica se y == x
//
//  Il numero di riga 15 sarà ricercato e non trovato nella tabella dei simboli, dove sarà inserito con il tipo L, e sarà assegnato alla posizione successiva del vettore, 01. Ricordate che l'istruzione rem non genera codicem perciò
//  il contatore di istruzioni non saàr incrementato.
//  In seguito sarà analizzata l'istruzione 
//
//  20 if y == x goto 60
//
//  Il numero di riga 20 sarà inserito nella tabella dei simboli e gli sarà assegnato il tipoL e la posizione successva del vettore LMS: 01. Il comando if indica che dovrà essere valutata una condizione. La variabile y non sarà 
//  ancora presente nella tabella dei simboli, perciò vi sarà inserita e gli sarà assegnato il tipo V e la posizione 98 di LMS. In seguito, saranno generate le istruzioni LMS che valuteranno la condizione. Dato che in LMS non 
//  c'è nessuna diretta corrispondenza per il costrutto if/goto, questo dovrà essere simulato eseguendo un calcolo con x e y e trasferendo il constrollo del programma in base al risultato. Il risultato della sottrazione di x da y
//  sarà zero, qualora y sia uguale a x, e perciò potrà essere usata l0istruzione branch zero con il risultato del calcolo per simulare l'istruzione if/goto. Il primo passo richiederà che y siacaricata nell'accumulatore dalla
//  posizione 99 di LMS, generando quindi l'istruzione 01 +2098. In seguito, x sarà sottratta dall'accumulatore , generando l'istruzione 02 +3199.
//  A questo punto, il valore contenuto nell'accumulatore potrà essere zero, positivo o negativo. Dato che l'operatore è ==, dovremo usare l'istruzione LMS brach zero. In primo luogo, cercheremo la posizione di destinaizone per 
//  il salto (60, in questo caso) nella tabella dei simboli, ma non la troveremo. Di conseguenza, il 60 dovrà essere immesso nella posizione 03 del vettore flags e dovrà essere generata l'istruzione 03 +4200. Infatti, non potremo
//  aggiungere la destinazione del salto, perchè non avremo ancora assegnato una posizione nel vettore LMS alla riga 60. Il contatore di istruzioni sarà incrementato a 04. 
//  Il compilatore procederà con l'istruzione 
//
//  25 rem incrementa y
//
//  Il numero di riga 25 sarà inserito nella tabella dei simboli con il tipo L e con la posizione 04 di LMS. Il contatore di istruzioni non sarà incrementato. 
//  Nel momento in cui l'istruzione
//
//  30 let y = y + 1
//
//  sarà analizzata, il numero di riga 30 sarà inserito nella tabella dei simboli con il tipo L e con la posizione 04 di LMS. Il comando let indica che la riga è un'istruzione di assegnamento e, di conseguenza, tutti i simboli 
//  della riga dovranno essere inseriti nella tabella dei simboli, qualora non vi siano già stati inclusi. L'intero 1 sarà aggiunto alla tabella dei simboli con il tipo C e con la posizione 97 di LMS. La parte destra dell'assegna
//  mento sarà quindi convertita dalla notazione infissa a quella polacca inversa. In seguito sarà valutata l'espressione in notazione polacca inversa (y 1 +). Il token y sarà individuato nella tebella dei simboli e la sua 
//  posizione di memoria sarà sistemata in cima alla pila. Una volta che avrà incontrato l'operatore +, la funzione di valutazione delle espressioni in notazione polacca inversa estrarrà due valori consecutivi dalla pila, 
//  assegnandoli rispettivamente agli operandi di destra e di sinistra dell'operatore e generando le istruizoni LMS
//
//  04 +2098	(load y)
//  05 +3097	(add 1)
//
//  Il risultato dell'espressione sarà immagazzinato in una posizione temporanea della memoria (96), con l'istruzione 
//
//  06 +2196	(store temporaneo)
//
//  e la posizione temporanea sarà sistemata sulla pila. Una volta che l'espressione sarà stata valutata, il risultato dovrà essere immagazzinato in y (ovverosia, nella variabile a sinistra di =). Di conseguenza, la posizione
//  temporanea sarà caricata nell'accumulatore e questo sarà immagazzinato in y, co le istruzioni
//
//  07 +2096	(load temporaneo)
//  08 +2198	(store y)
//
//  Vi sarete accorti immediatamente che le istruizoni LMS sembrano essere ridondanti. Discuteremo di questo tra breve. Nel momento in cui l'istruzione
//
//  35 rem aggiunge y al totale
//
//  sarà analizzata, il numero di riga 35 sarà inserito nella tabella dei simboli con il tipo L e con la posizione 09. L'istruzione
//
//  40 let t = t + y
//
//  è simile alla riga 30. La variabile t sarà dunque inserita nella tabella dei simboli con il tipo V e con la posizione 95 di LMS. Le istruzioni seguono la stessa logica e formato della riga 30, perciò saranno generate le 
//  istruzioni 09 +2095, 10 +3098, 11 +2194, 12 +2094 e 13 +2195. Osservate che il risultato di t + y sarà assegnato alla posizione temporanea 94, prima di essere assegnato a t (95). Ancora una volta, avrete notato che le 
//  istruzioni inserite nelle posizioni di memoria 11 e 12 sembrano essere ridondanti. Di nuovo discuteremo di ciò a breve. L'istruizone
//
//  45 rem ciclo y
//
//  è un commento, perciò la riga 45 sarà aggiunta alla tabella dei simboli con il tipo L e con la posizione 14 di LMS. L'istruzione
//
//  50 goto 20
//
//  trasferisce il controllo alla riga 20. In LMS l'equivalente di goto è l'istruzione di salto incondizionato (40) che trasferisce il controllo a una specifica posizione di LMS. Il compilatore cercherà dunque nella tabella dei 
//  simboli la riga 20 e rileverà che corrisponderà alla posizione 01 di LMS. Il codice dell'operazione (40) sarà moltiplicato per 100 e aggiunto alla posizione 01 così da generare l'istruzione 14 +4001. L'istruzione 
//
//  55 rem visualizza il risultato 
//
//  è un commento e, di conseguenza, la riga 55 sarà inserita nella tabella dei simboli con il tipo L e con la posizione 15. L'istruzione 
//
//  60 print t
//
//  è un'struzione di output. Il numero di riga 60 sarà inserito nella tabella dei simboli con il tipo L e con la posizione 15 di LMS. In LMS l'equivalente di print è il codice di operaizone 11 (write). La posizione di t sarà 
//  rilevata dalla tabella dei simboli e sarà aggiunta al prodotto tra 100 e il codice dell'operazione. L'istruzione 
//
//  99 end
//
//  è la riga finale del programma. Il numero di riga 99 sarà immagazzinato nella tebella dei simboli con il tipo L e con la posizione 16 di LMS. Il comando end genererà l'istruzione +4300(43 è halt in LMS), che sarà scritta come
//  istruzione finale nel vettore della memoria LMS.
//  Questo completa il primo passaggio del compilatore. Considereremo ora il secondo passaggio. Cercheremo nel vettore flags i valori diversi da -1. La posizione 03 contiene 60, perciò il compilatore saprà che l'istruzione 03 non 
//  è completa. Esso integrerà quindi l'istruzione ricercando il 60 nella tabella dei simboli, determinandone la sua posizione e aggiundendola a quella incompleta. In questo caso la ricerca determinerà che la riga 60 corrisponde
//  alla posizione 15 di LMS e, di cnseguenza, sarà generata l'istruzione completa 03 +4215 in sostituzione di 03 +4200. A questo punto il programma scritto in Semplice sarà stato compilato con successo.
//
//  Per costruire il compilatore, dovrete eseguire ognuna delle seguenti attività:
//
//  a) Modificate il simulatore, di Simpletron che avete scritto nell'Esercizio 7.19, in modo che prenda il suo input da un file specificato dall'utente (consulate il Capitolo 11). Il compilatore dovrà anche salvare i suoi risultati
//  in un file su disco, seguendo lo stesso formato dell'output sullo schermo.
//
//  b) Modificate l'algoritmo di conversione della notazione infissa a quella polacca inversa dell'Esercizio 12.12 in modo che elabori operandi interi con piu cifre e operandi corrispondenti a nomi di variabile formati da una sola
//  lettera. Consiglio: per individuare tutte le costanti e le variabili di un'espressione, potrà essere usata la funzione strtok della libreria standard, mentre le costanti di stringa potranno essere convertite in interi, usando
//  la funzione atoi della libreria standard. Nota: la rappresentazione dei dati dell'espressione in notaizone polacca inversa dovrà essere alterata in modo da supportare i nomi di variabile e le costanti intere.
//
//  c) Modificate l'algoritmo di valutazione delle espressioni in notazione polacca inversa, in modo che elabori operandi interi con piu cifre e operandi corrispondenti a nomi di variabile. L'algoritmo dovrà anche implementare la
//  variabile. L'algoritmo dovrà anche implementare la variante discussa in precendenza, in modo che siano prodotte le istruzioni LMS, invece di valutare direttamente l'espressione. Consiglio: per individuare tutte le costanti e 
//  le variabili di un'espressione, potrà essere convertite in interi usando la funzione strtok della libreria standard, mentre le costanti di stringa potranno essere convertite in interi usando lafunzione atoi della libreria stan
//  dard, mentre le costanti di stringa potranno essere convertite in interi usando la funzione atoi della libreria standard. Nota: la rappresentazione dei dati dell'espressione in  notazione polacca inversa dovrà essere alterata
//  in modd da supportare i nomi di variabile e le costanti intere.
//
//  c) Costruite il compilatore. Incorporate le parti (b) e (c) che valutino le espressioni delle istruzioni let. Il vostro programma dovrà contenere due funzioni che eseguano il primo e il secondo passo del compilatore. Entrambe
//  le funzioni potranno richiamarne altre per svolgere i loro compiti. 
//
//  ESERCIZIO 12.26
//
//  SEZIONE SPECIALE: COSTRUITE IL VOSTRO COMPILATORE
//
//  (Il linguaggio semplice) Prima di cominciare a costruire il complitare, discuteremo un semplice ma potente linguaggio di alto livello simile alle prime versioni del popolare linguaggio BASIC. Chiameremo questo linguaggio Semplice
//  Ogni costrutto eseguibile di Semplice sarà formato da un numero di riga e da questo linguaggio Semplice. I numeri di riga dovranno comparire in ordine crescente. Ogni istruzione incomincierà con uno dei seguenti comandi di 
//  Semplice: rem , input, let, print, goto, if/goto o end (Consultate la Figura 12.23). Eccettuato end, tutti i comandi potranno essere usati ripetutamente. Semplice valuterà soltanto delle espressioni intere usando gli operatori 
//   + , - , * e /. Questi operatori manterranno la stessa priorità che hanno in C. Potranno comunque essere  utilizzate delle parentesi per cambiare l'ordine di valutazione di un'espressione. Il nosttro compilatore di Semplice 
//  riconoscerà soltanto le lettere minuscole. Tutti i caratteri inclusi in un file di Semplice dovranno essere in minuscolo (quelli maiuscoli provocheranno un errore di sintassi, sempre che non compaiano in un'istruzione rem, nel 
//  qual caso saranno ignorati). I nomi di variabile saranno formati da una singola lettera. Il Semplice non consentirà nomi di variabile descrittivi, perciò queste dovranno essere descritte nei commenti in modo da indicare il loro
//  uso all'interno del programma. Il Semplice userà soltanto delle variabili intere e non sarà necessario dichiararle: basterà menzionare all'interno del programma un nome di variabile, perchè questa sia automaticamente dichiarata 
//  e inizializzata a zero. La sintassi di Semplice non consentirà la manipolaizone delle stringhe (lettura, scrittura, confronto ecc.). Il compilatore genererà un errore di sintassi, qualora incontri all'interno di un programma in 
//  linguaggio Semplice una stringa preceduta da un comando diverso da rem. Il nostro compilatore presumerà che i programmi in linguaggio Semplice siano stati immessi correttamente. L'Esercizio 12.29 chiederà al lettore di modificare
//  il compilatore cosi che possa eseguire la verifica della sintassi.Semplice userà l'istruizone condizionale if/goto  e quella incondizionata goto per alterare il flusso di controllo durante l'esecuzione del programma. Qualora 
//  l'istruzione if/goto saranno validi il controllo sarà trasferito a una riga specifica del programma. In una istruzione if/goto saranno validi i seguenti operatori relazionali e di uguaglianza : <, >, <=, >= , == o !=. La 
//  priorità di questi operatori sarà la stessa che hanno in C.
//  -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
//  -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  Prendiamo ora in considerazione alcuni programmi scritti in linguaggio Semplice che dimostreranno le caratteristiche di quest'ultimo. Il primo programma (Figura 12.24) leggerà due interi dalla tastiera, immagazzinerà i loro 
//  valori nelle variabili a e b e calcolerà e visualizzerà la loro somma (immagazzinata nella variabile c).
//  -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
//  -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  Figura 12.24 Determinare la somma di due interi.
//
//  Il programma della Figura 12.25 determinerà e visualizzerà il maggiore tra due numeri interi. Gli interi saranno letti dalla tastiera e immagazzinati in s e t. L'istruzione if/goto verificherà la condizione s >= t. Qualora la 
//  condizione sia vera, il controllo sarà trasferito alla riga 90 e s sarà visualizzato; altrimenti, verrà visualizzato t e il controllo sarà trasferito all'istruzione end della riga 99, dove il programma terminerà la propria
//  esecuzione.
//  -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
//  -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

// SVILUPPO TOP DOWN
//
// Variabili d'ambiente:
// 	Tabella dei simboli realizzata con vettore di struttura tableEntry di nome T
// 	Tabella delle segnalazioni realizzata con vettori interi flags
// 	Memoria Simpletron realizzata con Vettore di interi Memory
// 	Contatore delle istruzioni CountInstruction
// 	Contatore delle variabili / costanti CountVariable
// 	Buffer di caratteri num
//	Buffer di caratteri ist
//	Buffer di caratteri op
//	Buffer di caratteri match
//	Variabile intera op1
//	Variabile intera op2
//	Variabile intera jump per istruzioni goto
//	Variabile intera count per incrementare l'indice della tabella dei simboli
//
// Aquisire una riga in linguaggio Semplice
//
// Copia 1° Token in un Buffer num
// Copia 2° Token in un Buffer ist
//
// Se ist è uguale a print esegui il seguente codice 
// 	Ananza di un token e copia la stringa in op
// 	Poni T[count].Symbol uguale al risultato di Atoi(N)
// 	Poni T[count].type uguale a 'L'
// 	Poni T[count].Position = CountInstruction
//	Ricerca la posizione di op convertito in intero con atoi() nella tabella dei simboli
//	Genera la seguente istruzione 1000 + T.[posizione di op].position e ponila in memory[CountInstruction]
//	incrementa CountInstruction
//	incrementa count
//
// Se ist è uguale a input esegui il seguente codice
//	Avanza di token e copia la stringa in op
//	Poni T[count].symbol uguale al risultato di Atoi(N)
//	Poni T[count].type uguale a 'L'
//	Poni T[count].position = CountInstruction
//	incrementa count
//	Poni T[count].symbol uguale a op
//	Poni T[count].type uguale a 'V'
//	Poni T[count].position uguale CountVariable
//	incrementa count
//	Genera istruzione LMS 1100 + countVariable e ponila in Memory[CountInstruction]
//	incrementa CountInstruction
//	decrementa CountVariable
//
// Se ist è uguale a goto esegui il seguente codice 
//	Avanza di token e copia la stringa in op
//	Poni T[count].Symbol uguale al risultato di Atoi(N)
//	Poni T[count].type uguale a 'L'
//	Poni T[count].Position uguale a CountInstruction
//	incrementa count
//	Converti il Token in intero con Atoi(op) è ponilo nella Variabile jump
//	Ricerca il valore di T[indice].Symbol nella tabella dei simboli uguale jump
//	Se la ricerca da esito positivo genera la seguente istruzione 4000 + il valore contenuto in T[indice].position e inseriscila in memory[CountInstruction]
//	altrimenti genera la seguente istruzione 4000 e inseriscila in memory[CountInstruction] inserisci in flags[CountInstruction] il valore di jump
//	incrementa CountInstruction 
//
// Se ist è uguale a if esegue il seguente codice
// 	Poni T[count].Symbol uguale al risultato di Atoi(N)
// 	Poni T[count].type uguale a 'L'
// 	Poni T[count].position uguale a CountInstruction
// 	incrementa count e CountInstruction
// 	copia il resto della stringa in buffer di caratteri ist
// 	scorri il buffer di caratteri ist dalla posione 0 fino alla fine ricercando un carattere o un numero e quando lo trovi ricercalo nella tabella dei simboli se esiste passa al successivo altrimenti:
// 		- poni T[count].Symbol uguale al carattere o alla costante
//		- poni T[count].type uguale a 'C' o 'V'
//		- poni T[count].position uguale a CountInstruction
//		- incrementa count
//	Una volta verificata la presenza di tutte le variabili e costanti prosegui con l'estrazione del token e poni in op1 il risultato di Atoi(op)
//	Estrai il token successivo e ponilo nel buffer match
//	Estrai il token successivo e poni il risultato di Atoi(op) in op2
//
//	Se match è uguale a == esegui le seguenti le istruzioni
//		- Ricerca la posizione nella tabella dei simboli del valore di op1 T[index].position e genera la seguente istruzione LMS 2000 + T[index].position caricamento di op1  in accumulatore
//		- poni l'istruzione LMS in memory[CountInstruction] incrementa CountInstruction
//		- Ricerca la posizine nella tabella dei simboli del valore di op2 T[index].position e genera la seguente istruzione LMS 3100 + T[index].position sottrazione di op2 al valore contenuto nell'accumulatore
//		- poni l'istruzione LMS in memroy[CountInstruction] incrementa CountInstruction
//		- Se il valore dell'accumulatore è uguale a zero significa che op1 e op2 sono uguali pertanto puoi eseguire goto alla posizione che anremo a vedere
//			- Avanza token due volte fino ad arrivare alla posizione dove effettuare il salto e poni il risultato di Atoi(token) in jump
//			- Ricerca il valore T[index].Symbol nella tabella dei simboli uguale a jump 
//			- Se la ricerca da esito positivo genera la seguente istruzione 4200 + il valore contenuto in T[index].position e inseriscila in memory[CountInstruction] 
//			- Altimenti genera la seguente istruzione 4200 e inseriscila in memory[CountInstruction] inserisci in flags[CountInstruction] il valore di jump
//			- incrementa Count instraction
//		- Altimenti se il valore contenuto nell'accumulatore è maggiore di zero non fare nulla
//	
//	Se match è uguale a <
//		- Ricerca la posizione nella tabella dei simboli del valore di op1 T[index].position e genera la seguente istruzione LMS 2000 + T[index].position caricamento di op1  in accumulatore
//		- poni l'istruzione LMS in memory[CountInstruction] incrementa CountInstruction
//		- Ricerca la posizine nella tabella dei simboli del valore di op2 T[index].position e genera la seguente istruzione LMS 3100 + T[index].position sottrazione di op2 al valore contenuto nell'accumulatore
//		- poni l'istruzione LMS in memroy[CountInstruction] incrementa CountInstruction
//		- Se il valore dell'accumulatore è negativo significa che op1 è minore di op2 pertanto puoi eseguire goto alla posizione che anremo a vedere
//			- Avanza token due volte fino ad arrivare alla posizione dove effettuare il salto e poni il risultato di Atoi(token) in jump
//			- Ricerca il valore T[index].Symbol nella tabella dei simboli uguale a jump 
//			- Se la ricerca da esito positivo genera la seguente istruzione 4100 + il valore contenuto in T[index].position e inseriscila in memory[CountInstruction] 
//			- Altimenti genera la seguente istruzione 4100 e inseriscila in memory[CountInstruction] inserisci in flags[CountInstruction] il valore di jump
//			- incrementa Count instraction
//		- Altrimenti se il valore contenuto nell'accumulatore è maggiore o uguale a zero non fare nulla
//
//	Se match è uguale a >
//		- Ricerca la posizione nella tabella dei simboli del valore di op2 T[index].position e genera la seguente istruzione LMS 2000 + T[index].position caricamento di op2  in accumulatore
//		- poni l'istruzione LMS in memory[CountInstruction] incrementa CountInstruction
//		- Ricerca la posizine nella tabella dei simboli del valore di op1 T[index].position e genera la seguente istruzione LMS 3100 + T[index].position sottrazione di op1 al valore contenuto nell'accumulatore
//		- poni l'istruzione LMS in memroy[CountInstruction] incrementa CountInstruction
//		- Se il valore dell'accumulatore è negativo significa che op2 è minore di op1 pertanto puoi eseguire goto alla posizione che anremo a vedere
//			- Avanza token due volte fino ad arrivare alla posizione dove effettuare il salto e poni il risultato di Atoi(token) in jump
//			- Ricerca il valore T[index].Symbol nella tabella dei simboli uguale a jump 
//			- Se la ricerca da esito positivo genera la seguente istruzione 4100 + il valore contenuto in T[index].position e inseriscila in memory[CountInstruction] 
//			- Altimenti genera la seguente istruzione 4100 e inseriscila in memory[CountInstruction] inserisci in flags[CountInstruction] il valore di jump
//			- incrementa Count instraction
//		- Altrimenti se il valore contenuto nell'accumulatore è maggiore o uguale a zero non fare nulla
//
//	Se match è uguale a !=
//
//	Se match è uguale a <= 
//
//	Se match è uguale a >=
//
//
// Se ist è uguale a let esegui il seguente codice
// 	Poni T[count].Symbol uguale al risultato di Atoi(N)
// 	Poni T[count].type uguale a 'L'
// 	Poni T[count].position uguale a CountInstruction
// 	incrementa count e CountInstruction
// 	copia il resto della stringa in buffer di caratteri ist
// 	scorri il buffer di caratteri ist dalla posione 0 fino alla fine ricercando un carattere o un numero e quando lo trovi ricercalo nella tabella dei simboli se esiste passa al successivo altrimenti:
// 		- poni T[count].Symbol uguale al carattere o alla costante
//		- poni T[count].type uguale a 'C' o 'V'
//		- poni T[count].position uguale a CountInstruction
//		- incrementa count e CountInstruction
//
//	Una volta verificata la presenza di tutte le variabili modifica la stringa appena copiata nel buffer facendola partire dal primo carattere successivo al segno di '='
//	Converti la stringa che è una espressione in notazione polacca inversa
//	Scorri la stringa appena convertita in notazione polacca inversa dalla posizione 0
//	Se incontri una variabile o costante la inserisci in pila con push(V)
//	continua 
//	Se incontri un operatore lo copi nella variabile char op
//		- Estrai un valore dalla pila e inseriscilo in op1
//		- Ricerca la posizine nella tabella dei simboli del valore di op1 T[index].Symbol e genera la seguente istruzione LMS 2000 + T[index].position caricamento nell'accumulatore
//		- Memorizza questa istruzione in memory[CountInstruction] 
//		- incrementa CountInstruction
//		- Estrai un valore dalla pila e inseriscilo in op2
//		- Ricerca la posizine nella tabella dei simboli del valore di op2 T[index].Symbol e genera la seguente istruzione LMS in base al valore di op:
//			- '+' -> 3000 + T[index].position somma al valore contenuto nell'accumulatore
//			- '-' -> 3100 + T[index].position sottrazione al valore contenuto nell'accumulatore
//			- '%' -> 3200 + T[index].position divisione del valore contentuto nell'accumulatore
//			- '*' -> 3300 + T[index].position moltiplicazione per il valore contenuto nell'accumulatore
//		- Memorizza questa istruzione in memory[CountInstruction] e incrementa CountInstruction
//		- Posiziona il valore contenuto nell'accumulatore in una posizione temporanea quindi:
//			- Genera la seguente istruzione LMS : 2100 + CountVariable e decrementa CountVariable
//			- e Inserisci il valore appena calcolato in pila push
//			- Estrai successivo valore da stringa 
//			- Ricerca il valore nella Tabella dei simboli 
//			- pusha il valore nella pila
//			- Estrai il un nuovo carattere dalla stringa e inseriscilo in op
//			- Estrai il valore da pila e inserisco in accumulatore generando l'istruzione 2000 + il valore ricercato uguale a T[index].Position che è uguale a T[index].Symbol
//			- Estrai il secondo valore dalla pila e ricercane la posizione nella tabella dei simboli in base alla corrispondenza con T[index].Symbol
//			- Ricercare il tipo di istruzione in base all'operatore 
//			- Generare l'istruzione  e memorizzarla in memory[CountInstruction] successivamente incrementa CountInstruction
//			- Genera la seguente istruzione LMS : 2100 + CountVariable e decrementa CountVariable
//		- Se l'espressione è terminata richiamare il valore appena memorizzato da accumulatore in accumulatore e assegnarlo a posizione indicata alla sinistra dell'assegnamento
//		- Genera le seguenti istruzioni:
//			- 2000 + Valore memorizzato in posizione temporanea ri-caricato nell'accumulatore
//			- 2100 + ricerca della posizione dell'operando alla sinistra del carattere di assegnazione
//
// Altrimenti è rimasto rem
// 	Poni T[count].Symbol uguale al risultato di Atoi(N)
// 	Poni T[count].type uguale a 'L'
// 	Poni T[count].position uguale a CountInstruction

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "polacca.c"
#include "editSimple.c"
#include "simpletron.c"


#define SIZE 100

struct tableEntry{
	int symbol;	// è l'intero che conterrà la rappresentazione ASCII di una variabile (cararttere singolo), un numero di riga o una costante. 
	char type; 	// 'C' costante , 'L' linea , 'V' variabile
	int position; 	// da 00 a 99 la posizione puntata dal simbolo nella  memoria del Simpletron (vettore memory[])

};

typedef struct tableEntry tableEntry;

void initTable(tableEntry T[]);
void initflags(int []);
void printTable(tableEntry []);
void printFlag(int []);
void printMemory(int []);
int search(tableEntry[], int);
void evaluatePostfixExpression(char *expr,tableEntry T[],int *countVariable,int *countInstruction, int memory[], int returned);      //  Valuterà l'espressione in notaizone polacca inversa
void evaluatePostfixExpressionOptimazed(char *expr,tableEntry T[],int *countVariable, int *countInstruction, int memory[], int returned);    //  Valuterà l'espressione in notaizone polacca inversa con ottimizzazione della memoria

int main(){

struct tableEntry T[SIZE];	// Tabella dei simboli T

int memory[SIZE] = {0};		// Memoria del Simpletron 
int flags[SIZE] = {-1};		// Vettore delle segnalazioni flag
int countVariable = 99;		// Contatore Variabili e costanti
int countInstruction = 0;	// Contatore istruzioni
int count = 0;			// Contatore tabella simboli
int op1 = 0, op2 = 0, jump = 0, lms = 0;
int returned;

char num[10]; 
char ist[10];
char op[10];
char match[10];
char v[80];
char buf[80];
char *ptr;
char postfix[80];
char string[300];
char name[20];

FILE *ptFILE;

initTable(T);
initflags(flags);
inStruction temp;

void (*f[5]) (void) = {createFile,addRecord,updateRecord,eliminateRecord,stampa};
     
int c;
 
     do{
         c = menu();
         if(c >= 0 && c <= 4) (*f[c])();
     }while(c >= 0 && c <= 4);

     printf("\nCompilazione....\n");

     printf("\nNome file? : ");
     scanf("%s",name);
     //getchar();

     if((ptFILE = fopen(name,"r")) == NULL){
                 printf("\nImpossibile aprire il file in lettura...\n");
     }else{
                fread(&temp,sizeof(inStruction),1,ptFILE);
		while(!feof(ptFILE)){
                        printf("%2d %s",temp.line, temp.ist);
			//getchar();
			strcpy(v,temp.ist);
			strcpy(buf,v);

			ptr = strtok(v," ");	
			strcpy(num,ptr);    
			ptr = strtok(NULL," ");
			strcpy(ist,ptr);
			//printf("Numero %s Istruzione: %s\n",num,ist);

			if(strcmp(ist,"print") == 0){ 		// print
				ptr = strtok(NULL," ");
				strcpy(op,ptr);
				T[count].symbol = atoi(num);
				T[count].type = 'L';
				T[count].position = countInstruction;
				lms = 1100 + search(T,op[0]);
				memory[countInstruction] = lms;
				countInstruction++;
				count++;
			/*printf("Istruzione generata: %4d", lms);*/

			}else if(strcmp(ist,"input") == 0){ 	// input
				ptr = strtok(NULL," ");
				strcpy(op,ptr);
				T[count].symbol = atoi(num);
				T[count].type = 'L';
				T[count].position = countInstruction;
				count++;
				T[count].symbol = op[0];
				T[count].type = isalpha(op[0]) ? 'V' : 'C';
				T[count].position = countVariable;
				count++;
				lms = 1000 + countVariable;
				memory[countInstruction] = lms;
				countInstruction++;
				countVariable--;
			/*printf("Istruzione generata: %4d", lms);*/

			}else if(strcmp(ist,"goto") == 0){		// goto
				ptr = strtok(NULL," ");
				strcpy(op,ptr);
				T[count].symbol = atoi(num);
				T[count].type = 'L';
				T[count].position = countInstruction;
				count++;
				jump = atoi(op);
				if(search(T,jump) == 0){
					lms = 4000;
					memory[countInstruction] = lms;
					flags[countInstruction] = jump;
				}else{
					lms = 4000 + search(T,jump);
					memory[countInstruction] = lms;
				}
				countInstruction++;
				/*printf("Istruzione generata: %4d", lms);*/

			}else if(strcmp(ist,"if") == 0){	// if/goto
				/*puts("Istruzione if goto");*/
				T[count].symbol = atoi(num);
				T[count].type = 'L';
				T[count].position = countInstruction;
				countInstruction++;
				memmove(v,v+6,80);
				/*printf("\nStringa v : %s\n",v);*/
				strcpy(buf,v);
				ptr = strtok(buf," ");
				op1 = ptr[0];
				if(search(T,op1) == 0){
					T[count].symbol = ptr[0];
					T[count].type = isalpha(ptr[0]) ? 'V' : 'C';
					T[count].position = countVariable;
				
				
				if(T[count].type == 'V'){
					lms = 1000 + countVariable;
					memory[countInstruction++] = lms;
					/*printf("\nIstruzione inserita : %4d",lms);*/
				}else{
					memory[countVariable] = T[count].symbol - 48;
					/*printf("\nValore %d inserito in memory[%2d]",memory[countVariable], countVariable);*/
				}
				countVariable--;
				count++;
				}
				ptr = strtok(NULL," ");
				strcpy(match,ptr);
				ptr = strtok(NULL," ");
				op2 = ptr[0];
			
				if(search(T,op2) == 0){
					T[count].symbol = ptr[0];
					T[count].type = isalpha(ptr[0]) ? 'V' : 'C';
					T[count].position = countVariable;
					if(T[count].type == 'V'){
						lms = 1000 + countVariable;
						memory[countInstruction++] = lms;
						/*printf("\nIstruzione inserita : %4d",lms);*/
					}else{
						memory[countVariable] = T[count].symbol - 48;
						/*printf("\nValore %d inserito in memory[%2d]",memory[countVariable], countVariable);*/
					}
					countVariable--;
					count++;
				}
				ptr = strtok(NULL," ");
				ptr = strtok(NULL," ");
				jump = atoi(ptr);

	
				if(strcmp(match,"==") == 0){ // se deve confrontare l'uguaglianza di due numeri
					/*printf("\nValore di op1 : %3d",op1);*/
					lms = 2000 + search(T,op1); 
					memory[countInstruction] = lms;
					countInstruction++;
					/*printf("\nCarica nell'accumulatore il valore del primo operando: %4d ",lms);*/
					lms = 3100 + search(T,op2);
					memory[countInstruction] = lms;
					countInstruction++;
					/*printf("\nSottrae al primo valore quello del secondo : %4d",lms);*/
					if(search(T,jump) != 0){
						lms = 4200 + search(T,jump);
						/*printf("\nSalta ad una specifica locazione di memoria: %4d",lms);*/
					}else{
						lms = 4200;
						flags[countInstruction] = jump;
						/*printf("\nImposta l'istruzione lms pari a %4d e imposta flags[%d] = %d",lms,countInstruction,flags[countInstruction]);*/
					}
			 
					memory[countInstruction] = lms;
					countInstruction++;
			
				}else if(strcmp(match,"<") == 0){ // se deve confrontare l'uguaglianza di due numeri
					/*printf("\nValore di op1 : %3d",op1);*/
					lms = 2000 + search(T,op1); 
					memory[countInstruction] = lms;
					countInstruction++;
					/*printf("\nCarica nell'accumulatore il valore del primo operando: %4d ",lms);*/
					lms = 3100 + search(T,op2);
					memory[countInstruction] = lms;
					countInstruction++;
					/*printf("\nSottrae al primo valore quello del secondo : %4d",lms);*/
					if(search(T,jump) != 0){
						lms = 4100 + search(T,jump);
						/*printf("\nSalta ad una specifica locazione di memoria: %4d",lms);*/
					}else{
						lms = 4100;
						flags[countInstruction] = jump;
						/*printf("\nImposta l'istruzione lms pari a %4d e imposta flags[%d] = %d",lms,countInstruction,flags[countInstruction]);*/
					}
		 
					memory[countInstruction] = lms;
					countInstruction++;
			
				}else if(strcmp(match,">") == 0){ // se deve confrontare l'uguaglianza di due numeri
					/*printf("\nValore di op2 : %3d",op2);*/
					lms = 2000 + search(T,op2); 
					memory[countInstruction] = lms;
					countInstruction++;
					/*printf("\nCarica nell'accumulatore il valore del primo operando: %4d ",lms);*/
					lms = 3100 + search(T,op1);
					memory[countInstruction] = lms;
					countInstruction++;
					/*printf("\nSottrae al primo valore quello del secondo : %4d",lms);*/
					if(search(T,jump) != 0){
						lms = 4100 + search(T,jump);
						/*printf("\nSalta ad una specifica locazione di memoria: %4d",lms);*/
					}else{
						lms = 4100;
						flags[countInstruction] = jump;
						/*printf("\nImposta l'istruzione lms pari a %4d e imposta flags[%d] = %d",lms,countInstruction,flags[countInstruction]);*/
					}
		 
					memory[countInstruction] = lms;
					countInstruction++;
			
					}
	
			}else if(strcmp(ist,"let") == 0){	// let
				//puts("Istruzione let");
				T[count].symbol = atoi(num);
				T[count].type = 'L';
				T[count].position = countInstruction;
				countInstruction++;
				jump = strlen(buf)-6;
				memmove(v,buf+7,jump);
				//puts(v);
				//getchar();
				v[jump+1] = '\0';
				strcpy(buf,v);
				//printf("\nControllo variabili ,stringa da elaborare : %s",v);
				jump = 0;
				while(v[jump] != '\0'){
					if(isalpha(v[jump]) || isdigit(v[jump])){
					if(search(T,v[jump]) == 0){
						//printf("\n%c da inserire",v[jump]);
						T[count].symbol = v[jump];
						T[count].type = isalpha(v[jump]) ? 'V' : 'C';
						T[count].position = countVariable;
						if(T[count].type == 'V'){
							lms = 1000 + countVariable;
							memory[countInstruction++] = lms;
							//printf("\nIstruzione inserita : %4d",lms);
						}else{
							memory[countVariable] = T[count].symbol - 48;
							//printf("\nValore %d inserito in memory[%2d]",memory[countVariable], countVariable);
						}
						countVariable--;
						count++;
					}else
								;
						//printf("\n%c trovato",ptr[0]);
					}
					jump++;
					}

					returned = v[0];
					//printf("\nValore al quale ritornare il valore dell'espressione %c\n",returned);
				
					if((ptr = strchr(v,'\n')) != NULL) *ptr = '\0';

					memmove(v,v+4,strlen(v));
					strcpy(buf,v);
					//puts(v);
					convertToPostfix(v,postfix);
					//printf("\nEspressione :%s. Ora che sono inserite costanti e variabili la trasformo in notazione polacca inversa... %s\n",buf,postfix);	
					//printf("... ora generiamo le istruzioni in semplice...\n");
					evaluatePostfixExpressionOptimazed(postfix,T,&countVariable,&countInstruction,memory,returned);     //  Valuterà l'espressione in notaizone polacca inversa.
					//puts(postfix);	

			}else if(strcmp(ist,"end") == 0){
					//printf("\nRaggiunta la fine\n");
					T[count].symbol = atoi(num);
					T[count].type = 'L';
					T[count].position = countInstruction;
					lms = 4300;
					memory[countInstruction] = lms;
					countInstruction++;
					count++;
			}else if (strcmp(ist,"rem") == 0){					// rem
	
					//puts("Istruizone rem");
					T[count].symbol = atoi(num);
					T[count].type = 'L';
					T[count].position = countInstruction;
					count++;
			}

                         fread(&temp,sizeof(inStruction),1,ptFILE);
                 }
         }

	for(count = 0; count < SIZE; count++)
		if(flags[count] != -1 )	memory[count] += search(T,flags[count]);
		
	

     	printTable(T);
	putchar('\n');
	printFlag(flags);
	putchar('\n');
	printMemory(memory);
	putchar('\n');

	/*
     	strcat(name,"_LMS");

	// SALVATAGGIO DELLE ISTRUZIONI LMS IN FILE
	
	if((ptFILE = fopen(name,"w")) == NULL){
		printf("\nImpossibile salvare le istruzioni...");
	}else{
     	 	printf("\nSalvataggio istruzioni LMS nel file %s...\n",name);
		printMemory(memory);
		fwrite(memory,sizeof(char),100,ptFILE);
		fclose(ptFILE);
	}
	
	// CANCELLAZIONE DELLA MEMORIA DEL SIMPLETRON

	for(c = 0; c <= 99; c++)
		memory[c] = 0;

	// LETTURA DEL FILE CON LE STRUZIONI LMS

	if((ptFILE = fopen(name,"r")) == NULL){
		printf("\nImpossibile salvare le istruzioni...");
	}else{
		printf("\n...Lettura dei file %s...\n",name);
		fread(memory,sizeof(char),100,ptFILE);
		fclose(ptFILE);
	}

	// ESUZUZIONE CODICE LMS...
	
	printf("\nInizio esecuzione del Simpletron...");
	getchar();

	
	print_start();
	getchar();  
	simpletron(memory); 
	*/

return 0;
}


void printTable(tableEntry T[]){
	int i;
	printf("\n\nTabella Simboli --->");

	for(i = 0; i < SIZE; i++)
		if(T[i].symbol != 0) printf("\nSymbol %3d Type %c Position %3d",T[i].symbol,T[i].type,T[i].position);
}

void printFlag(int flags[]){
	int i;

	printf("\n\nVettore Flags --->");

	for(i = 0; i < SIZE; i++)
		if(flags[i] != -1) printf("\nflags[%2d] = %d",i,flags[i]);


}

void printMemory(int mem[]){

	int i;
	for(i = 0; i < SIZE; i++)
		if(mem[i]) printf("\nMemory[%2d] -- > %2d",i,mem[i]);

}

int search(tableEntry T[], int c){
	int i, position = 0;
	for(i = 0; i < SIZE; i++ )
		if(T[i].symbol == c) position = T[i].position;
	
	return position;

}
void initTable(tableEntry T[]){
	tableEntry E;
	int i;

	E.symbol = 0;
	E.type = 'L';
	E.position = 0;

	for(i  = 0; i < SIZE; i++)
		T[i] = E;
}


void initflags(int flags[]){
int i;

for(i = 0; i < SIZE; i++)
	flags[i] = -1;

}

void evaluatePostfixExpression(char *expr,tableEntry T[],int *countVariable, int *countInstruction, int memory[], int returned){      //  Valuterà l'espressione in notaizone polacca inversa.
 
 int i = 0, op2 , temp = 0, lms, accumulator = 0;

 /*printf("\n\n ----------------- Inizio valutazione espressione in notazione polacca inversa ------------------ \n\n");*/
 
 while(expr[i] != '\0'){
 
         if((isdigit(expr[i]) || isalpha(expr[i])) && accumulator == 0 && temp == 0){
                 /*printf("Inserisco il valore nell'accumulatore: %4d ",*/lms = 2000 + search(T,expr[i]);
		 memory[*countInstruction] = lms;
		 (*countInstruction)++;
                 accumulator = 1;
                 i++;
	}else if(temp != 0 && (isdigit(expr[i]) || isalpha(expr[i])) && accumulator == 0){
                 /*printf("\nRiporto nell'accumulatore il valore precendentemente archiviato %4d ",*/lms = 2000 + temp;
		 memory[*countInstruction] = lms;
		 (*countInstruction)++;
                 temp = 0;
                 accumulator = 1;
                 i++;
         }else if((isdigit(expr[i]) || isalpha(expr[i])) && accumulator != 0){
                 op2 = search(T,expr[i]);
                 //printf("\nIndividuo un altro operando: %2d",op2);
		 i++;
         }else if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/'){ 		// operazione
                 //printf("\nOperatore : %c",expr[i]);
                
		 if(expr[i] == '+') 		 /*printf("\nIstruzioni per la somma %4d",*/lms = 3000 + op2;
		 else if(expr[i] == '-')	 /*printf("\nIstruzioni per la sottrazione %4d",*/lms = 3100 + op2;
		 else if(expr[i] == '*')	 /*printf("\nIstruzioni per la moltiplicazione %4d",*/lms = 3300 + op2;
		 else if(expr[i] == '/')	 /*printf("\nIstruzioni per la divisione %4d",*/lms = 3200 + op2;
		 
		 memory[*countInstruction] = lms;
		 (*countInstruction)++;
                 /*printf("\nSposto la somma nella memoria del Simpletron %4d",*/lms = 2100 + *countVariable;   // Istruzione da eliminare per l'ottimizzazione del compilatore
		 memory[*countInstruction] = lms;								// Istruzione da eliminare per l'ottimizzazione del compilatore								
		 (*countInstruction)++;
                 temp = *countVariable;		// temp archivia il valore di countVariable perchè successivamente serve sapere da quale quale posizione della memoria riprendere l'operatore
                 (*countVariable)--;            // Decremento di countVariable per conteggio delle variabili archiviate.
                 accumulator = 0;		// accumulator uguale a 0 perchè abbiamo spostato il valore dall'accumulatore ad una locazione di memoria
                 i++;
         }else{
                 i++;
 
 	} 
 }

 /*printf("\nGiro terminato riporto il valore nell'accumulatore %4d", memory[*countInstruction] =  2000 + temp;*/
 /*(*countInstruction)++; */
 /*printf(" e assegno il valore contenuto nell'accumulatore : %4d",*/ memory[*countInstruction] =  2100 + search(T,returned);
 (*countInstruction)++;
 //printf("\n\n ----------------- Termine valutazione espressione in notazione polacca inversa ------------------ \n\n");

}


void evaluatePostfixExpressionOptimazed(char *expr,tableEntry T[],int *countVariable, int *countInstruction, int memory[], int returned){      //  Valuterà l'espressione in notaizone polacca inversa.
 
 int i = 0, op2 , temp = 0, lms, accumulator = 0;

 /*printf("\n\n ----------------- Inizio valutazione espressione in notazione polacca inversa ------------------ \n\n");*/
 
 while(expr[i] != '\0'){
 
         if((isdigit(expr[i]) || isalpha(expr[i])) && accumulator == 0 && temp == 0){
                 /*printf("Inserisco il valore nell'accumulatore: %4d ",*/lms = 2000 + search(T,expr[i]);
		 memory[*countInstruction] = lms;
		 (*countInstruction)++;
                 accumulator = 1;
                 i++;
	}/*else if(temp != 0 && (isdigit(expr[i]) || isalpha(expr[i])) && accumulator == 0){
                 printf("\nRiporto nell'accumulatore il valore precendentemente archiviato %4d ",lms = 2000 + temp;
		 memory[*countInstruction] = lms;
		 (*countInstruction)++;
                 temp = 0;
                 accumulator = 1;
                 i++;
         }*/else if((isdigit(expr[i]) || isalpha(expr[i])) && accumulator != 0){
                 op2 = search(T,expr[i]);
                 //printf("\nIndividuo un altro operando: %2d",op2);
		 i++;
         }else if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/'){ 		// operazione
                 //printf("\nOperatore : %c",expr[i]);
                
		 if(expr[i] == '+') 		 /*printf("\nIstruzioni per la somma %4d",*/lms = 3000 + op2;
		 else if(expr[i] == '-')	 /*printf("\nIstruzioni per la sottrazione %4d",*/lms = 3100 + op2;
		 else if(expr[i] == '*')	 /*printf("\nIstruzioni per la moltiplicazione %4d",*/lms = 3300 + op2;
		 else if(expr[i] == '/')	 /*printf("\nIstruzioni per la divisione %4d",*/lms = 3200 + op2;
		 
		 memory[*countInstruction] = lms;
		 (*countInstruction)++;
                 /*printf("\nSposto la somma nella memoria del Simpletron %4d",lms = 2100 + *countVariable; */  // Istruzione da eliminare per l'ottimizzazione del compilatore
		 //memory[*countInstruction] = lms;								// Istruzione da eliminare per l'ottimizzazione del compilatore								
		 //(*countInstruction)++;
                 //temp = *countVariable;		// temp archivia il valore di countVariable perchè successivamente serve sapere da quale quale posizione della memoria riprendere l'operatore
                 //(*countVariable)--;            // Decremento di countVariable per conteggio delle variabili archiviate.
                 //accumulator = 0;		// accumulator uguale a 0 perchè abbiamo spostato il valore dall'accumulatore ad una locazione di memoria
                 i++;
         }else{
                 i++;
 
 	} 
 }

 /*printf("\nGiro terminato riporto il valore nell'accumulatore %4d",*/ //memory[*countInstruction] =  2000 + temp;
 //(*countInstruction)++; 
 /*printf(" e assegno il valore contenuto nell'accumulatore : %4d",*/ memory[*countInstruction] =  2100 + search(T,returned);
 (*countInstruction)++;
 //printf("\n\n ----------------- Termine valutazione espressione in notazione polacca inversa ------------------ \n\n");

}
