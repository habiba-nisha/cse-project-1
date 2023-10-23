PROG = main
CC = gcc
OUTPUT_DIR=./output

${PROG}: ${PROG}.c
	${CC} ${PROG}.c -o ${OUTPUT_DIR}/${PROG}.exe && ${OUTPUT_DIR}/${PROG}.exe


clean :
	rm -rf ${OUTPUT_DIR}/*.exe
