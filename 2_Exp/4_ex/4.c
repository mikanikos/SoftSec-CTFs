// Compile with `gcc -static -s -m32 -fno-stack-protector -O0 -std=c99`

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/file.h>

static int off = 0;

int main( void )
{
	char name[1024], addr[1024];
	int jackpot;
	srand( time(NULL) );

	printf("Give me your name: "); fflush(stdout); gets( name );
	printf("Give me the jackpot: "); fflush(stdout); scanf("%d", &jackpot);

	int r = rand();
        printf("%d\n", off);

	if( jackpot == r )
	{
		char ch;
		int fd = open("flag", O_RDONLY);

		if( !flock(fd, LOCK_EX | LOCK_NB) &&
			lseek(fd, off++, SEEK_SET) != -1 &&
			read(fd, &ch, 1) == 1 )
		{
			printf( "I'm gonna show you 1 character from flag: %c\n", ch );
			fflush(stdout);
		}

		flock(fd, LOCK_UN);
		close( fd );

		printf( "Give me your address to send you the money: ");
		fflush(stdout);
		gets( addr );
	} else {
		printf( "Better luck next time!\n" );
		fflush(stdout);
	}
}
