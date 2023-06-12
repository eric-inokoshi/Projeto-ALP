#include <iostream>

using namespace std;

int main()
{
	const int QUANTIDADE_PRODUTOS = 18;
	double preco_produtos[QUANTIDADE_PRODUTOS] = {0.00};
	int estoque_produtos[QUANTIDADE_PRODUTOS] = {5}; // quantidade inicial de 5 para todos produtos
	std::string nome_produtos[QUANTIDADE_PRODUTOS];
	nome_produtos[0] = "Agua Natural";
	preco_produtos[0] = 2.00;
	nome_produtos[1] = "Agua com Gas";
	preco_produtos[1] = 2.50;
	nome_produtos[2] = "Suco de Uva";
	preco_produtos[2] = 3.00;
	nome_produtos[3] = "Suco de Laranja";
	preco_produtos[3] = 3.00;
	nome_produtos[4] = "Coca-cola";
	preco_produtos[4] = 3.50;
	nome_produtos[5] = "Guarana";
	preco_produtos[5] = 3.50;
	nome_produtos[6] = "Fanta Uva";
	preco_produtos[6] = 3.50;
	nome_produtos[7] = "Fanta Laranja";
	preco_produtos[7] = 3.50;
	nome_produtos[8] = "Sprite";
	preco_produtos[8] = 3.50;
	nome_produtos[9] = "RedBull";
	preco_produtos[9] = 9.00;
	nome_produtos[10] = "Monster";
	preco_produtos[10] = 8.00;
	nome_produtos[11] = "Doritos";
	preco_produtos[11] = 5.00;
	nome_produtos[12] = "Fandangos";
	preco_produtos[12] = 5.00;
	nome_produtos[13] = "Cheetos";
	preco_produtos[13] = 5.00;
	nome_produtos[14] = "Torcida Queijo";
	preco_produtos[14] = 4.00;
	nome_produtos[15] = "Chocolate ao Leite";
	preco_produtos[15] = 3.00;
	nome_produtos[16] = "Twix";
	preco_produtos[16] = 2.00;
	nome_produtos[17] = "Amendoim";
	preco_produtos[17] = 3.00;

	int cod_produto = 0;
	int modo_adm = 0;
	int repor = 0;
	double fatur = 0;

	// Usando while e switch-case para voltar sempre para a tela de vendas
	while (cod_produto != 20)
	{
		cout << "=====================================================================" << endl;
		for (int i = 0; i < QUANTIDADE_PRODUTOS; i++)
		{
			cout << (i + 10) << " - " << nome_produtos[i] << " - R$" << preco_produtos[i] << endl;
		}
		cout << "Informe o codigo do produto: " << endl;
		cin >> cod_produto;

		// se digitou 0, entra no modo administrador
		if (cod_produto == 0)
		{
			modo_adm = 0; // para entrar no while abaixo e mostrar o menu de administrador
						// se esquecer de zerar, ele nao entra no while na segunda vez que digitar 0
			while (modo_adm != 4)
			{
				cout << "=====================================================================" << endl;
				cout << "=== MODO ADMINISTRADOR	===" << endl;
				cout << "Escolha uma opcao: " << endl
					 << "1 - Repor produtos" << endl
					 << "2 - Inventario" << endl
					 << "3 - Faturamento" << endl
					 << "4 - Sair" << endl;
				cin >> modo_adm;

				switch (modo_adm)
				{
				case 1:
				{
					cout << "=====================================================================" << endl;
					cout << "=== REPOR PRODUTOS ===" << endl;
					cout << "Quantidade de produtos na maquina: " << endl;

					for (int i = 0; i < QUANTIDADE_PRODUTOS; i++)
					{
						cout << nome_produtos[i] << ": " << estoque_produtos[i] << endl;
					}

					cout << "Desejar repor os produtos?" << endl
						 << "1 - Sim" << endl
						 << "2 - Nao" << endl;
					cin >> repor;

					if (repor == 1)
					{
						for (int i = 0; i < QUANTIDADE_PRODUTOS; i++)
						{
							estoque_produtos[i] = 5;
						}
						cout << "Produtos Repostos" << endl;
					}
					else
					{
						cout << "Produtos nao Repostos" << endl;
					}
					break;
				}
				case 2:
				{
					cout << "=====================================================================" << endl;
					cout << "=== INVENTARIO ===" << endl;
					cout << "Quantidade de produtos na maquina: " << endl;

					for (int i = 0; i < QUANTIDADE_PRODUTOS; i++)
					{
						cout << nome_produtos[i] << ": " << estoque_produtos[i] << endl;
					}
					break;
				}

				case 3:
				{
					cout << "=====================================================================" << endl;
					cout << "=== FATURAMENTO ===" << endl;
					cout << "O valor faturado eh de: R$" << fatur << endl;

					double valor_do_estoque = 0.00;
					for (int i = 0; i < QUANTIDADE_PRODUTOS; i++)
					{
						valor_do_estoque += (preco_produtos[i] * estoque_produtos[i]);
					}

					cout << "O valor disponivel para faturar eh de: R$" << valor_do_estoque << endl;
					break;
				}

				case 4:
				{
					cout << "=====================================================================" << endl;
					cout << "Voltando ao menu de compras..." << endl;
					break;
				}
				}
			}
			continue; // volta para o inicio do while (cod_produto != 20) para nao entrar no switch-case abaixo e voltar para o menu de compras
		}

		// subtrai 10 do cod_produto para ficar de acordo com o indice do array
		cod_produto -= 10;
		cout << "=====================================================================" << endl;
		cout << "Produto selecionado: " << nome_produtos[cod_produto] << endl;
		if (estoque_produtos[cod_produto] == 0)
		{
			cout << "Nao ha " << nome_produtos[cod_produto] << " disponivel" << endl;
			continue; // volta para o inicio do while (cod_produto != 20)
		}

		double pag = 0;
		double troco = 0;

		cout << "Informe o valor inserido na maquina: " << endl;
		cin >> pag;

		if (pag < preco_produtos[cod_produto])
		{
			cout << "Dinheiro insuficiente" << endl;
			continue; // volta para o inicio do while (cod_produto != 20)
		}
		else if (pag == preco_produtos[cod_produto])
		{
			cout << "Sem troco necessario. Pode retirar o produto!" << endl;
		}
		else
		{
			troco = pag - preco_produtos[cod_produto];
			cout << "O troco eh de: R$" << troco << endl
				 << "Pode retirar o troco e o produto!" << endl;
		}
		fatur += preco_produtos[cod_produto];
		estoque_produtos[cod_produto]--;
	}

	system("pause");
	return 0;
}
