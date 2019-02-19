void main() {

	GPIO->PIN_CNF[SCL_PIN] = 0;
	GPIO->PIN_CNF[SDA_PIN] = 0;
	
	return 0;
}