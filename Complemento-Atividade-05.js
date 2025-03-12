function dividirNumeros() {
    try {
        // solicita q insira dois numeros
        let numerador = parseFloat(prompt("Digite o numerador:"));
        let denominador = parseFloat(prompt("Digite o denominador:"));

        // verificaçao dos numeros
        if (isNaN(numerador) || isNaN(denominador)) {
            throw new Error("Entrada inválida. Certifique-se de digitar números.");
        }

        // verifica se o denominador é zero
        if (denominador === 0) {
            throw new Error("Divisão por zero não é permitida.");
        }

        // tenta realizar a divisão
        let resultado = numerador / denominador;
        alert(`O resultado da divisão é: ${resultado}`);

    } catch (erro) {
        // captura e exibe o erro
        alert(`Erro: ${erro.message}`);

    } finally {
        // executa sempre (independentemente de exceções)
        alert("Operação de divisão concluída.");
    }
}

// chama a função e executar o programa
dividirNumeros();