# GS_IOT

# Sobre o projeto
Descrição
VoltUp é um aplicativo inovador que revoluciona a forma como você experiencia a mobilidade elétrica.
Com o VoltUp, encontrar estações de carregamento, planejar rotas e conectar-se com outros entusiastas de veículos elétricos nunca foi tão fácil.

## Funcionalidades Principais
  * Localizador de estações, verificando se o local está apto para uso
  * Planejamento de rotas, traçando o melhor trajeto para ir até o local
  * Perfil personalizado, podendo ver ultimas vezes e locais em que carregou seu veículo
    

# Pré requisitos

Para executar a solução, primeiramente é necessário ter a instalação do Node.js e do Node-RED na máquina.

Para instalação do Node.js, [clique aqui][1] para ver um tutorial: 

Após instalação do Node.js, para instalar o Node-RED na máquina, basta abrir o prompt de comando no windows, e digitar o comando:

*npm install -g --unsafe-perm node-red*

# Início

Para dar inicio no processo de execução do comando, primeiramente é necessário abrir o site [Wokwi][2] , clicar em ESP32
descer a tela, e clicar novamente em ESP32, automáticamente um projeto será gerado.

Após isso, é necessário abrir o arquivo **diagram.json** que está anexado ao repositório, copiar o código completo,
voltar para o seu projeto, clicar na aba superior com nome também de **diagram.json** e colar o código json copiado.

Após essa etapa, o esquema do circuito já estará montado.

O próximo passo é abrir o arquivo **sketch.ino**, também anexado ao repositório, copiar o código completo,
voltar para o seu projeto, clicar na aba superior com nome tambem de **sketch.ino** e colar o código copíado.

A princípio, a primeira parte do processo está concluida, você já tem o código e o desenho para fazer o projeto funcionar.

## Integração

Para inciar o Node-RED, é necessário abrir o prompt de comando e digitar : "node-red" (sem aspas), assim o servidor será iniciado.

Após inicialização, temos acesso ao caminho : http://127.0.0.1:1880/

Abrindo o navedador, colamos o link, e o Node-RED já estará funcionando.
A princípio, dentro dele, será necessário instalar "paletas", para isso, clice no menu em sanduíche na parte superior direita,
vá em "gerenciar paletas", clice no campo instalar, na parte superior e digite primeiramente por : "node-red-dashboard" (sem aspas)
e clique em instalar, na sequencia procure por: "node-red-contrib-web-worldmap" (sem aspas) e também instale-o.

Feito isso, clice novamente no menu em sanduíche na parte superior direita, mas agora vá em Importar, aberto a aba
é só colar o código do arquivo **flows.json**, que também está anexado ao repositório e clicar em importar.

Pronto, o seu programa basicamente está pronto para ser utilizado.

## Usabilidade

Para abrir o dashboard, é só digitar no navegador o caminho: http://127.0.0.1:1880/ui/

Alguns dados utilizados na dashboard, foram pegos aleatóriamente, apenas para fazer a representação de como funcionaria,
pensando em integração com mapas, bancos de dados etc.

Porém, a parte principal de atuação de sensores, funciona de forma simples, pelo dashboard podemos ver o status do local onde a pessoa selecionar,
verificando se existe ou não algum veículo parado naquele local, através de um sensor de presença, e através do sensor de temperatura,
verificar qual temperatura está no local onde será feito a carga no carro, isso é de exterma importância pois, a temperaturas mais elevadas,
(para maioria dos carros elétricos, se considera superior a 30ºC) pode causar perda de desempenho e durabilidade, pois como naturalmente
o carra aquece ao ser carregado, com a temperatura ambiente alta, pode-se ter problemas de funcionamento.

# Explicação geral de funcionamento.

Para começar a entender como o programa funcina, primeiro daremos uma olhada na imagem do esquema desenvolvido em arduino.




[1]: https://www.freecodecamp.org/portuguese/news/como-instalar-o-node-js-e-o-npm-no-windows/
[2]: https://wokwi.com/
