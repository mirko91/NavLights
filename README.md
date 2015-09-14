# NavLights EXP
NavLights EXP è un piccolo PCB che include: <br>
-1 regolatore di tensione LM1117 a 5v <br>
-4 mosfet IRLML2502 capaci di supportare 4.2A <br>
-4 connettori per ogni mosfet per collegare 4 LED da 1w per canale <br>

Lo scopo è di simulare le luci di navigazione degli aerei di linea nel seguente modo: <br>
-strobi da applicare nella deriva e alle estremità delle ali <br>
-luce di posizione rossa e verde <br>
-beacon anticollisione da posizionare sulla fusoliera <br>
-fari di atterraggio <br>

Il sistema di potenza viene pilotato da una scheda Arduino e permette di configurare luminosità e tempi di accensione dei LED e inoltre legge un canale della ricevente per il cambio di modalità: <br>
-luci spente <br>
-luci di navigazione e strobi accesi <br>
-luci di navigazione, strobi e faro di atterraggio accesi  <br>
