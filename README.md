# <p align="center">FX</p>

Este projeto serve para calcular o valor de uma função em um determinado ponto
x, sendo que esta função é passada por uma string digitada pelo usuario.

# Como usa-lo

Antes de ser executado pela primeira vez é necessario compila-lo.

## Compilar

* Windows
Caso você já tenha C++11, ou superior, e ele esteja nas variaveis de ambiente 
PATH, basta executar o arquivo compile.bat.
Caso não seja tenha, é mais facil instalar uma IDE, como o Code:Blocks, e 
simplesmente clicar em compilar.

* Linux
Muitas distros já posuem o g++. Caso você não tenha pasta abrir um terminal e 
digitar "apt-get install g++". Para erificar se o g++ esta instalado digite 
"g++ --version".
Com o g++ já instalado, basta digitar os comandos:
"g++ -std=c++11 fx.cpp main.cpp -o main.exe",
"g++ -std=c++11 fx.cpp IntDef.cpp -o IntDef.exe" e
"g++ -std=c++11 df_x.cpp -o df_x.exe"
(são os mesmos ccomando que estão no arquio 'compile.bat')


## Calcular f(x)

* Abra o main.exe
* Informe a função
* Informe o valor de x
* Aguarde o precessamento, se demorar demais precione 'ctrl+c' para encerar o 
programa.

## Integrar f(x) (somente o calculo da integral definida)

* Abra o IntDef.exe
* Informe a função
* Informe o limite inferior
* Informe o limite superior
* Informe a precisão (dx = 1/10^precisão)
* Aguarde o precessamento, se demorar demais precione 'ctrl+c' para encerar o 
programa. (essa etapa usa processamento paralelo, não se assuste se os coolers 
ficarem no máximo)

## Derivar f(x)		(lista de funcoes ainda meio limitada)

* Abra o IntDef.exe
* Informe a função
* Aguarde o precessamento 
(o simbolo '#' significa um que o numero posterior é negatio)


# May The Force Be With You
