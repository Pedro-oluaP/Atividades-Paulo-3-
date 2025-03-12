#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Funcionario {
    string nome;
    int departamento;
    int horasTrabalhadas;
    double salarioBase;
    double horaExtra;
    double insalubridade;
    double bonificacao;
    double inss;
    double ir;
    double salarioLiquido;
};

const double valorHoraDep1 = 22.00;
const double valorHoraDep2 = 12.00;
const double taxaINSS = 0.07;
const double taxaIR = 0.12;
const double planoSaude = 20.00;

double calcularSalarioBase(int horas, int departamento) {
    return horas * (departamento == 1 ? valorHoraDep1 : valorHoraDep2);
}

double calcularHoraExtra(int horas, int departamento) {
    if (horas > 40) {
        return (horas - 40) * (departamento == 1 ? valorHoraDep1 : valorHoraDep2) * 2;
    }
    return 0;
}

double calcularInsalubridade(double salarioBase, int departamento) {
    return departamento == 2 ? salarioBase * 0.15 : 0;
}

double calcularBonificacao(double salarioBase, int horas, int departamento) {
    if (departamento == 1) {
        if (horas > 40) return salarioBase * 0.10;
        if (horas > 30) return salarioBase * 0.05;
        if (horas > 20) return salarioBase * 0.03;
    }
    return 0;
}

double calcularINSS(double salarioBruto) {
    return salarioBruto * taxaINSS;
}

double calcularIR(double salarioBruto) {
    return salarioBruto * taxaIR;
}

double calcularSalarioLiquido(double salarioBruto, double inss, double ir) {
    return salarioBruto - inss - ir - planoSaude;
}

void imprimirFolhaPagamento(const vector<Funcionario>& funcionarios) {
    cout << setw(5) << "Ordem" << setw(15) << "Nome" << setw(12) << "Salario Base" << setw(10) << "Hora Extra"
         << setw(12) << "Insalubridade" << setw(12) << "Bonificacao" << setw(6) << "INSS"
         << setw(6) << "IR" << setw(14) << "Plano Saude" << setw(14) << "Salario Liquido" << endl;

    for (size_t i = 0; i < funcionarios.size(); ++i) {
        const Funcionario& f = funcionarios[i];
        cout << setw(5) << i + 1 << setw(15) << f.nome << setw(12) << f.salarioBase << setw(10) << f.horaExtra
             << setw(12) << f.insalubridade << setw(12) << f.bonificacao << setw(6) << f.inss
             << setw(6) << f.ir << setw(14) << planoSaude << setw(14) << f.salarioLiquido << endl;
    }
}

int main() {
    vector<Funcionario> funcionarios(5);

    for (int i = 0; i < 5; ++i) {
        cout << "Funcionario " << i + 1 << ":\n";
        cout << "Nome: ";
        cin >> funcionarios[i].nome;
        cout << "Departamento (1 = Administrativo / 2 = Producao): ";
        cin >> funcionarios[i].departamento;
        cout << "Horas trabalhadas no mes: ";
        cin >> funcionarios[i].horasTrabalhadas;

        funcionarios[i].salarioBase = calcularSalarioBase(funcionarios[i].horasTrabalhadas, funcionarios[i].departamento);
        funcionarios[i].horaExtra = calcularHoraExtra(funcionarios[i].horasTrabalhadas, funcionarios[i].departamento);
        funcionarios[i].insalubridade = calcularInsalubridade(funcionarios[i].salarioBase, funcionarios[i].departamento);
        funcionarios[i].bonificacao = calcularBonificacao(funcionarios[i].salarioBase, funcionarios[i].horasTrabalhadas, funcionarios[i].departamento);

        double salarioBruto = funcionarios[i].salarioBase + funcionarios[i].horaExtra + funcionarios[i].insalubridade + funcionarios[i].bonificacao;
        funcionarios[i].inss = calcularINSS(salarioBruto);
        funcionarios[i].ir = calcularIR(salarioBruto);
        funcionarios[i].salarioLiquido = calcularSalarioLiquido(salarioBruto, funcionarios[i].inss, funcionarios[i].ir);
    }

    imprimirFolhaPagamento(funcionarios);

    return 0;
}
