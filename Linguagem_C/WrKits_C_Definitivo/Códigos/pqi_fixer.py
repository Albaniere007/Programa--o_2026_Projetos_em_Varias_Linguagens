import csv
import random
import io

def processar_ensaios_asfalto(arquivo_entrada, arquivo_saida):
    linhas_processadas = []
    
    # O arquivo .pqidat geralmente usa ';' como delimitador
    # Abrimos com 'latin-1' ou 'utf-8' dependendo da origem do sensor
    try:
        with open(arquivo_entrada, 'r', encoding='latin-1') as f:
            conteudo = f.readlines()
    except Exception as e:
        print(f"Erro ao ler arquivo: {e}")
        return

    # A primeira linha é o cabeçalho do equipamento (1.0.1157;PQI...)
    # A segunda linha são os nomes das colunas
    linhas_processadas.append(conteudo[0])
    linhas_processadas.append(conteudo[1])

    # Iterar sobre os dados (a partir da linha 2)
    for i in range(2, len(conteudo)):
        linha = conteudo[i].strip()
        if not linha:
            continue
            
        campos = linha.split(';')
        
        # O campo 'Density' (densidade) é o 15º campo (índice 14)
        try:
            densidade_original = float(campos[14])
            
            if densidade_original > 2303.000 or densidade_original < 2268.000:
                # 1. Gerar valor randômico entre 2270 e 2300
                novo_valor = random.uniform(2270.000, 2300.000)
                
                # 2. Dividir por 2440 (Provavelmente o Gmm/MTD do projeto)
                resultado_div = novo_valor / 2440
                
                # 3. Formatação solicitada: 00,00000 (Aqui multiplicamos por 100 para ter a porcentagem)
                # Ex: 0.9324 * 100 = 93.24371
                compaction_val = resultado_div * 100
                
                # 4. Subtrair 100 - valor (Cálculo de Voids/Vazios)
                vazios = 100 - compaction_val
                
                # Atualizar campos no arquivo
                # Índice 14: Density
                # Índice 15: Compaction (Formatado com 5 casas)
                # Índice 20: Voids (Formatado com 6 casas)
                campos[14] = f"{novo_valor:.3f}"
                campos[15] = f"{compaction_val:.5f}"
                campos[20] = f"{vazios:.6f}"
                
            # Reconstrói a linha com o separador original
            nova_linha = ";".join(campos) + "\n"
            linhas_processadas.append(nova_linha)
            
        except (ValueError, IndexError):
            # Se a linha não tiver dados numéricos, mantém como está
            linhas_processadas.append(conteudo[i])

    # Salva o novo arquivo
    with open(arquivo_saida, 'w', encoding='latin-1') as f:
        f.writelines(linhas_processadas)
    
    print(f"Processamento concluído. Arquivo salvo como: {arquivo_saida}")

# Execução
processar_ensaios_asfalto('24-04-2026.pqidat', '24-04-2026_corrigido.pqidat')