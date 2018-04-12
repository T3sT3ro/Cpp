//
// Created by Tooster on 10.04.2018.
//

#include <iostream>
#include "expressions/expression.hpp"
#include "expressions/unary/sin.hpp"
#include "expressions/nullary/Phi.hpp"
#include "expressions/binary/sub.hpp"
#include "expressions/nullary/pi.hpp"
#include "expressions/binary/add.hpp"
#include "expressions/nullary/num.hpp"
#include "expressions/binary/mul.hpp"
#include "expressions/nullary/var.hpp"
#include "expressions/nullary/e.hpp"
#include "expressions/unary/cos.hpp"
#include "expressions/unary/exp.hpp"
#include "expressions/unary/ln.hpp"
#include "expressions/unary/abs.hpp"
#include "expressions/unary/addInv.hpp"
#include "expressions/unary/mulInv.hpp"
#include "expressions/binary/div.hpp"
#include "expressions/binary/log.hpp"
#include "expressions/binary/mod.hpp"
#include "expressions/binary/pow.hpp"

using namespace std;

void pr_var() {
    auto vx = Var::getVars();
    cout << "variables: {";
    for (auto v: vx) cout << "\t'" << v.first << ":" << v.second;
    cout << "}" << endl;
}

void pr(Expression *e) {
    cout << std::fixed;
    cout.precision(3);
    cout << e->toString() << "\t=\t" << e->eval() << endl;
}

void demo() {
    cout << endl << "\t-= DEMO =-" << endl;
    Var::setVar("x", 10);
    Var::setVar("y", 200);
    Var::setVar("z", 3000);

    pr_var();
    auto dmm = new Var("x");
    pr(new Num(7));
    pr(new Pi());
    pr(new E());
    pr(new Phi());
    pr(new Var("x"));
    pr(new Sin(dmm));
    pr(new Cos(dmm));
    pr(new Exp(dmm));
    pr(new Ln(dmm));
    pr(new Abs(dmm));
    pr(new AddInv(new Num(7)));
    pr(new AddInv(new Num(-7)));
    pr(new AddInv(dmm));
    pr(new MulInv(dmm));
    pr(new Add(dmm, dmm));
    pr(new Sub(dmm, dmm));
    pr(new Mul(dmm, dmm));
    pr(new Div(dmm, dmm));
    pr(new Log(dmm, dmm));
    pr(new Mod(dmm, dmm));
    pr(new Pow(dmm, dmm));
    cout << "\t-= DEMO END =-" << endl << endl;
}

int main() {
    demo();
    pr(new Sin(new Phi()));
    pr(new Sub(new Pi(), new Add(new Num(2), new Mul(new Var("x"), new Num(7)))));

    auto e1 = new Div(
            new Mul(
                    new Sub(
                            new Var("x"),
                            new Num(1)),
                    new Var("x")),
            new Num(2));

    auto e2 = new Div(
            new Add(
                    new Num(3),
                    new Num(5)),
            new Add(
                    new Num(2),
                    new Mul(
                            new Var("x"),
                            new Num(7))));

    auto e3 = new Sub(
            new Add(
                    new Num(2),
                    new Mul(
                            new Var("x"),
                            new Num(7))),
            new Add(
                    new Mul(
                            new Var("x"),
                            new Num(3)),
                    new Num(5)));

    auto e4 = new Div(
            new Cos(
                    new Mul(
                            new Add(
                                    new Var("x"),
                                    new Num(1)
                            ),
                            new Var("x")
                    )
            ),
            new Pow(
                    new E(),
                    new Pow(
                            new Var("x"),
                            new Num(2)
                    )
            )
    );

    cout << std::fixed;
    cout.precision(3);
    for (double i = 0.00; i < 1.00; i += 0.02) {
        Var::setVar("x", i);
        cout << "x = " << Var::getVar("x") << ":\t"
             << e1->eval() << "\t"
             << e2->eval() << "\t"
             << e3->eval() << "\t"
             << e4->eval() << endl;
    }

    pr(e1);
    pr(e2);
    pr(e3);
    pr(e4);
    pr(new Sub(new Sub(new Num(1), new Num(7)),
               new Sub(new Num(2), new Num(42))));

    pr(new Pow(new Sub(new Num(1),
                       new Div(new Num(3), new Num(5))),
               new Mod(new Mul(new Num(7), new Var("x")),
                       new Add(new Num(7), new Num(9)))));

    cout.flush();
}