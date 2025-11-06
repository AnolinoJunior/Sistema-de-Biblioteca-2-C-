# 📚 Sistema de Biblioteca em C (Parte 2)

Este projeto implementa um **sistema de biblioteca em linguagem C** com suporte a **cadastro de livros** e **controle de empréstimos**.  
Foi desenvolvido para fins educacionais na disciplina de **Estrutura de Dados**, utilizando **`structs`**, **alocação dinâmica de memória** e **menu interativo**.

---

## 🧩 Funcionalidades

### 📖 Gerenciamento de Livros
- Cadastrar novos livros (nome, autor, editora, edição)
- Listar todos os livros cadastrados
- Indicar se cada livro está **disponível** ou **emprestado**

### 👥 Sistema de Empréstimos
- Realizar empréstimos de livros disponíveis
- Registrar o nome do usuário que pegou o livro
- Listar todos os empréstimos realizados
- Impedir o empréstimo de livros já emprestados

### ⚙️ Recursos Técnicos
- Alocação dinâmica de memória com `malloc` e `calloc`
- Liberação correta da memória com `free`
- Função auxiliar para limpar o buffer de entrada
- Estrutura modular e segura (uso de `fgets` e `scanf_s`)

---

## 🧱 Estruturas Principais

### `struct Livro`
```c
struct Livro {
    char nome[100];
    char autor[100];
    char editora[100];
    int edicao;
    int disponivel; // 1 = disponível, 0 = emprestado
};
