class Funcionario:
    def __init__(self, nome, departamento, horas_trabalhadas):
        self.nome = nome
        self.departamento = departamento
        self.horas_trabalhadas = horas_trabalhadas
        self.salario_base = 0
        self.hora_extra = 0
        self.insalubridade = 0
        self.bonificacao = 0
        self.inss = 0
        self.ir = 0
        self.salario_liquido = 0

# Constantes
VALOR_HORA_DEP1 = 22.00
VALOR_HORA_DEP2 = 12.00
TAXA_INSS = 0.07
TAXA_IR = 0.12
PLANO_SAUDE = 20.00

def calcular_salario_base(horas, departamento):
    return horas * (VALOR_HORA_DEP1 if departamento == 1 else VALOR_HORA_DEP2)

def calcular_hora_extra(horas, departamento):
    if horas > 40:
        return (horas - 40) * (VALOR_HORA_DEP1 if departamento == 1 else VALOR_HORA_DEP2) * 2
    return 0

def calcular_insalubridade(salario_base, departamento):
    return salario_base * 0.15 if departamento == 2 else 0

def calcular_bonificacao(salario_base, horas, departamento):
    if departamento == 1:
        if horas > 40:
            return salario_base * 0.10
        elif horas > 30:
            return salario_base * 0.05
        elif horas > 20:
            return salario_base * 0.03
    return 0

def calcular_inss(salario_bruto):
    return salario_bruto * TAXA_INSS

def calcular_ir(salario_bruto):
    return salario_bruto * TAXA_IR

def calcular_salario_liquido(salario_bruto, inss, ir):
    return salario_bruto - inss - ir - PLANO_SAUDE

def imprimir_folha_pagamento(funcionarios):
    print(f"{'Ordem':<5} {'Nome':<15} {'Salario Base':<12} {'Hora Extra':<10} {'Insalubridade':<12} {'Bonificacao':<12} {'INSS':<6} {'IR':<6} {'Plano Saude':<14} {'Salario Liquido':<14}")
    for i, func in enumerate(funcionarios):
        print(f"{i+1:<5} {func.nome:<15} {func.salario_base:<12.2f} {func.hora_extra:<10.2f} {func.insalubridade:<12.2f} {func.bonificacao:<12.2f} {func.inss:<6.2f} {func.ir:<6.2f} {PLANO_SAUDE:<14.2f} {func.salario_liquido:<14.2f}")

def main():
    funcionarios = []
    for i in range(5):
        print(f"Funcionario {i+1}:")
        nome = input("Nome: ")
        departamento = int(input("Departamento (1 = Administrativo / 2 = Producao): "))
        horas_trabalhadas = int(input("Horas trabalhadas no mes: "))
        
        func = Funcionario(nome, departamento, horas_trabalhadas)
        func.salario_base = calcular_salario_base(func.horas_trabalhadas, func.departamento)
        func.hora_extra = calcular_hora_extra(func.horas_trabalhadas, func.departamento)
        func.insalubridade = calcular_insalubridade(func.salario_base, func.departamento)
        func.bonificacao = calcular_bonificacao(func.salario_base, func.horas_trabalhadas, func.departamento)
        
        salario_bruto = func.salario_base + func.hora_extra + func.insalubridade + func.bonificacao
        func.inss = calcular_inss(salario_bruto)
        func.ir = calcular_ir(salario_bruto)
        func.salario_liquido = calcular_salario_liquido(salario_bruto, func.inss, func.ir)
        
        funcionarios.append(func)
    
    imprimir_folha_pagamento(funcionarios)

if __name__ == "__main__":
    main()