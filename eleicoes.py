# O código é do @BrennoSullivan, só tô colocando aqui pra ficar mais fácil pro pessoal copiar.
import schedule
import time
from datetime import datetime

import requests
import json
import pandas as pd


def resultado_eleicoes():
    data = requests.get(
        'https://resultados.tse.jus.br/oficial/ele2022/544/dados-simplificados/br/br-c0001-e000544-r.json')

    json_data = json.loads(data.content)

    candidato = []
    partido = []
    votos = []
    porcentagem = []

    for informacoes in json_data['cand']:
        
        if informacoes['seq'] == '2' or informacoes['seq'] == '3' or informacoes['seq'] == '4' or informacoes['seq'] == '1':
            candidato.append(informacoes['nm'])
            votos.append(informacoes['vap'])
            porcentagem.append(informacoes['pvap'])
            
    df_eleicao = pd.DataFrame(list(zip(candidato, votos, porcentagem)), columns = [
        'Candidato', 'Nº de Votos', 'Porcentagem'
    ])

    print(df_eleicao)
resultado_eleicoes()
schedule.every(1).minutes.do(resultado_eleicoes)

while True:
    schedule.run_pending()
    time.sleep(1)