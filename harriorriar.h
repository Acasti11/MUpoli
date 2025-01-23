#ifndef HARRIORRIAR_H
#define HARRIORRIAR_H

void jokoaAurkeztuAOH(void);
int aukeraPosibleakAurkeztuLehenengoaAOH(int harriarenIrudia, int artaziarenIrudia, int papelarenIrudia,
                                         int errepikatuta);
int aukeraPosibleakAurkeztuBigarrenaAOH(int harriarenIrudia, int artaziarenIrudia, int papelarenIrudia,
                                        int errepikatuta);
void errepikatutaAOH(void);
int harriOrriArIrabazleaAOH(int lehenengoAukera, int bigarrenAukera);
void amaierakoPantailaAOH(int irabazlea, int lehenengoIrudia, int bigarrenIrudia);
void bakoitzakAukeratutakoaAOH(int lehenengoAukera, int bigarrenAukera, int lehenengoIrudia, int bigarrenIrudia,
                               int harriarenIrudia, int artaziarenIrudia, int papelarenIrudia);
int harriOrriAr(void);

#endif
