package main

import "fmt"

//Phone a phone interface
type Phone interface {
	call()
}
type oppo struct{}

func (oppoPhone oppo) call() {
	fmt.Println("hello i'm oppo")
}

type vivo struct{}

func (vivoPhone vivo) call() {
	fmt.Println("helllo i'm vivo")
}
func main() {
	oppoVariable := new(oppo)
	oppoVariable.call()
}
