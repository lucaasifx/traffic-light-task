# 📌 Emulação de Semáforo com LEDs e Temporizadores

## 📖 Descrição do Projeto
Este projeto tem como objetivo emular o funcionamento de um semáforo utilizando LEDs e temporizadores em microcontroladores RP2040, utilizando a placa BitDogLab. Para a simulação, o sistema controla três LEDs (vermelho, amarelo e verde) e é capaz de emular as mudanças de estado de um semáforo real.

Na BitDogLab, passamos a controlar apenas dois LEDs (vermelho e verde), sendo o amarelo uma composição entre eles para que as cores do semáforo permaneçam fiés a realidade.

### 🎯 Objetivos do Projeto:
- Utilizar **temporizadores** para alternar os estados do semáforo automaticamente.
- Controlar três LEDs (vermelho, amarelo e verde) na simulação e dois LEDs (vermelho e verde) na BitDogLab.
- Criar um sistema eficiente combinando **hardware e software**.

---

## 🛠 Componentes Utilizados
- Placa BitDogLab (RP2040)
- Simulação:

  - LED Vermelho conectado à **GPIO 13**

  - LED Amarelo conectado à **GPIO 1**

  - LED Verde conectado à **GPIO 11**
- BitDogLab:
  - LED Vermelho conectado à **GPIO 13**
  - LED Verde conectado à **GPIO 11**
  - LED Amarelo (LED vermelho e verde ligados simultaneamente)

---

## 🔧 Funcionalidades Implementadas
3. **LED Vermelho** acende por 3 segundos e é desligado.
1. **LED Verde** acende por 3 segundos e é desligado.
2. **LED Amarelo** acende por 3 segundos e é desligado.
4. **Ciclo de repetição contínuo** baseado em temporizadores.
5. **Implementação eficiente** evitando polling contínuo.

---

## Estrutura do Projeto
O projeto foi desenvolvido em C e possui suporte tanto para a simulação do circuito utilizando o **Wokwi** quanto para testes na BitDogLab. A estrutura de diretórios é organizada para facilitar o desenvolvimento e a compilação com a extensão **Raspberry Pi Pico** no VS Code.

### Diretórios Principais
- BitDoglab/:
  - src/: Contém o arquivo principal do código-fonte (main.c).
  - src/lib/: Contém os arquivos de cabeçalho (.h) das bibliotecas implementadas e as suas respectivas implementações.
- Simulacao/:
  - src/: Contém o arquivo principal do código-fonte (main.c).
  - src/lib/: Contém os arquivos de cabeçalho (.h) das bibliotecas implementadas e as suas respectivas implementações.
  - wokwi/: Contém o arquivo de simulação do circuito Wokwi (diagram.json e wokwi.toml)

## 🚀 Como Executar o Projeto
1. Clone este repositório:
   
```bash
   git clone https://github.com/lucaasifx/traffic-light-task.git
```

2. Abra o projeto no VS Code.

3. Certifique-se de que a extensão **Raspberry Pi Pico** e  **Wokwi** estão instaladas e configuradas corretamente.
4. Clique no ícone da extensão da Pico<br>
  ![image](https://github.com/user-attachments/assets/28cdb91b-16e2-4687-a6a1-950f219ddf34)
5. Selecione importar projeto para que a pasta build seja gerada automaticamente:<br>
![image](https://github.com/user-attachments/assets/b0dc78cd-f619-4648-9b5b-d509c65800d7)
  - Selecione o caminho do projeto e clique em Import: <br>
![image](https://github.com/user-attachments/assets/9abe1447-0f62-4b30-a70c-5b342020d3a6)
-  Se deseja compilar o projeto da Simulação, navegue até ./traffic-light-task/Simulacao
-  Se deseja carregar o software embarcado na placa BitDogLab, navegue até ./traffic-light-task/BitDogLab

6. Navegue até a opção Compilar Projeto:<br>
![image](https://github.com/user-attachments/assets/366a506d-171c-4c30-9577-e61d1575da33)

7. Se desejar testar no simulador, abra o arquivo diagram.json e inicie a simulação. <br>
![image](https://github.com/user-attachments/assets/0aa2885c-b246-4aa4-bf57-66adf6907bda)


---

## 📹 Demonstração em Vídeo
📺 **Veja o projeto em ação**:

🔗 [Vídeo de demonstração no hardware](https://www.youtube.com/)

---

