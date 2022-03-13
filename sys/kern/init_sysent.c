/*
 * System call switch table.
 *
 * DO NOT EDIT-- this file is automatically generated.
 * created from	@(#)syscalls.master	8.6 (Berkeley) 03/30/95
 */

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/signal.h>
#include <sys/mount.h>
#include <sys/syscallargs.h>
int	nosys();
int	exit();
int	fork();
int	read();
int	write();
int	open();
int	close();
int	wait4();
int	link();
int	unlink();
int	chdir();
int	fchdir();
int	mknod();
int	chmod();
int	chown();
int	obreak();
int	getfsstat();
int	getpid();
int	mount();
int	unmount();
int	setuid();
int	getuid();
int	geteuid();
int	ptrace();
int	recvmsg();
int	sendmsg();
int	recvfrom();
int	accept();
int	getpeername();
int	getsockname();
int	access();
int	chflags();
int	fchflags();
int	sync();
int	kill();
int	getppid();
int	dup();
int	pipe();
int	getegid();
int	profil();
#ifdef KTRACE
int	ktrace();
#else
#endif
int	sigaction();
int	getgid();
int	sigprocmask();
int	getlogin();
int	setlogin();
int	acct();
int	sigpending();
int	sigaltstack();
int	ioctl();
int	reboot();
int	revoke();
int	symlink();
int	readlink();
int	execve();
int	umask();
int	chroot();
int	msync();
int	vfork();
int	sbrk();
int	sstk();
int	ovadvise();
int	munmap();
int	mprotect();
int	madvise();
int	mincore();
int	getgroups();
int	setgroups();
int	getpgrp();
int	setpgid();
int	setitimer();
int	swapon();
int	getitimer();
int	getdtablesize();
int	dup2();
int	fcntl();
int	select();
int	fsync();
int	setpriority();
int	socket();
int	connect();
int	getpriority();
int	sigreturn();
int	bind();
int	setsockopt();
int	listen();
int	sigsuspend();
#ifdef TRACE
int	vtrace();
#else
#endif
int	gettimeofday();
int	getrusage();
int	getsockopt();
#ifdef vax
int	resuba();
#else
#endif
int	readv();
int	writev();
int	settimeofday();
int	fchown();
int	fchmod();
int	rename();
int	flock();
int	mkfifo();
int	sendto();
int	shutdown();
int	socketpair();
int	mkdir();
int	rmdir();
int	utimes();
int	adjtime();
int	setsid();
int	quotactl();
#ifdef NFS
int	nfssvc();
#else
#endif
int	statfs();
int	fstatfs();
#ifdef NFS
int	getfh();
#else
#endif
#if defined(SYSVSHM) && !defined(alpha)
#else
#endif
int	setgid();
int	setegid();
int	seteuid();
#ifdef LFS
int	lfs_bmapv();
int	lfs_markv();
int	lfs_segclean();
int	lfs_segwait();
#else
#endif
int	stat();
int	fstat();
int	lstat();
int	pathconf();
int	fpathconf();
int	getrlimit();
int	setrlimit();
int	getdirentries();
int	mmap();
int	nosys();
int	lseek();
int	truncate();
int	ftruncate();
int	__sysctl();
int	mlock();
int	munlock();
int	undelete();
#if defined(SYSVSHM) && 0
int	shmat();
int	shmctl();
int	shmdt();
int	shmget();
#else
#endif

#ifdef COMPAT_43
#define compat_43(func) __CONCAT(compat_43_,func)

int	compat_43(creat)();
int	compat_43(lseek)();
int	compat_43(stat)();
int	compat_43(lstat)();
#ifdef KTRACE
#else
#endif
int	compat_43(fstat)();
int	compat_43(getkerninfo)();
int	compat_43(getpagesize)();
int	compat_43(mmap)();
int	compat_43(wait)();
int	compat_43(gethostname)();
int	compat_43(sethostname)();
int	compat_43(accept)();
int	compat_43(send)();
int	compat_43(recv)();
int	compat_43(sigvec)();
int	compat_43(sigblock)();
int	compat_43(sigsetmask)();
int	compat_43(sigstack)();
int	compat_43(recvmsg)();
int	compat_43(sendmsg)();
#ifdef TRACE
#else
#endif
#ifdef vax
#else
#endif
int	compat_43(recvfrom)();
int	compat_43(setreuid)();
int	compat_43(setregid)();
int	compat_43(truncate)();
int	compat_43(ftruncate)();
int	compat_43(getpeername)();
int	compat_43(gethostid)();
int	compat_43(sethostid)();
int	compat_43(getrlimit)();
int	compat_43(setrlimit)();
int	compat_43(killpg)();
int	compat_43(quota)();
int	compat_43(getsockname)();
#ifdef NFS
#else
#endif
int	compat_43(getdirentries)();
#ifdef NFS
#else
#endif
#if defined(SYSVSHM) && !defined(alpha)
int	compat_43(shmsys)();
#else
#endif
#ifdef LFS
#else
#endif
#if defined(SYSVSHM) && 0
#else
#endif

#else /* COMPAT_43 */
#define compat_43(func) nosys
#endif /* COMPAT_43 */

#define	s(type)	sizeof(type)

struct sysent sysent[] = {
	{ 0, 0,
	    nosys },				/* 0 = syscall */
	{ 1, s(struct exit_args),
	    exit },				/* 1 = exit */
	{ 0, 0,
	    fork },				/* 2 = fork */
	{ 3, s(struct read_args),
	    read },				/* 3 = read */
	{ 3, s(struct write_args),
	    write },				/* 4 = write */
	{ 3, s(struct open_args),
	    open },				/* 5 = open */
	{ 1, s(struct close_args),
	    close },				/* 6 = close */
	{ 4, s(struct wait4_args),
	    wait4 },				/* 7 = wait4 */
	{ 2, s(struct compat_43_creat_args),
	    compat_43(creat) },			/* 8 = compat_43 creat */
	{ 2, s(struct link_args),
	    link },				/* 9 = link */
	{ 1, s(struct unlink_args),
	    unlink },				/* 10 = unlink */
	{ 0, 0,
	    nosys },				/* 11 = obsolete execv */
	{ 1, s(struct chdir_args),
	    chdir },				/* 12 = chdir */
	{ 1, s(struct fchdir_args),
	    fchdir },				/* 13 = fchdir */
	{ 3, s(struct mknod_args),
	    mknod },				/* 14 = mknod */
	{ 2, s(struct chmod_args),
	    chmod },				/* 15 = chmod */
	{ 3, s(struct chown_args),
	    chown },				/* 16 = chown */
	{ 1, s(struct obreak_args),
	    obreak },				/* 17 = break */
	{ 3, s(struct getfsstat_args),
	    getfsstat },			/* 18 = getfsstat */
	{ 3, s(struct compat_43_lseek_args),
	    compat_43(lseek) },			/* 19 = compat_43 lseek */
	{ 0, 0,
	    getpid },				/* 20 = getpid */
	{ 4, s(struct mount_args),
	    mount },				/* 21 = mount */
	{ 2, s(struct unmount_args),
	    unmount },				/* 22 = unmount */
	{ 1, s(struct setuid_args),
	    setuid },				/* 23 = setuid */
	{ 0, 0,
	    getuid },				/* 24 = getuid */
	{ 0, 0,
	    geteuid },				/* 25 = geteuid */
	{ 4, s(struct ptrace_args),
	    ptrace },				/* 26 = ptrace */
	{ 3, s(struct recvmsg_args),
	    recvmsg },				/* 27 = recvmsg */
	{ 3, s(struct sendmsg_args),
	    sendmsg },				/* 28 = sendmsg */
	{ 6, s(struct recvfrom_args),
	    recvfrom },				/* 29 = recvfrom */
	{ 3, s(struct accept_args),
	    accept },				/* 30 = accept */
	{ 3, s(struct getpeername_args),
	    getpeername },			/* 31 = getpeername */
	{ 3, s(struct getsockname_args),
	    getsockname },			/* 32 = getsockname */
	{ 2, s(struct access_args),
	    access },				/* 33 = access */
	{ 2, s(struct chflags_args),
	    chflags },				/* 34 = chflags */
	{ 2, s(struct fchflags_args),
	    fchflags },				/* 35 = fchflags */
	{ 0, 0,
	    sync },				/* 36 = sync */
	{ 2, s(struct kill_args),
	    kill },				/* 37 = kill */
	{ 2, s(struct compat_43_stat_args),
	    compat_43(stat) },			/* 38 = compat_43 stat */
	{ 0, 0,
	    getppid },				/* 39 = getppid */
	{ 2, s(struct compat_43_lstat_args),
	    compat_43(lstat) },			/* 40 = compat_43 lstat */
	{ 1, s(struct dup_args),
	    dup },				/* 41 = dup */
	{ 0, 0,
	    pipe },				/* 42 = pipe */
	{ 0, 0,
	    getegid },				/* 43 = getegid */
	{ 4, s(struct profil_args),
	    profil },				/* 44 = profil */
#ifdef KTRACE
	{ 4, s(struct ktrace_args),
	    ktrace },				/* 45 = ktrace */
#else
	{ 0, 0,
	    nosys },				/* 45 = unimplemented ktrace */
#endif
	{ 3, s(struct sigaction_args),
	    sigaction },			/* 46 = sigaction */
	{ 0, 0,
	    getgid },				/* 47 = getgid */
	{ 2, s(struct sigprocmask_args),
	    sigprocmask },			/* 48 = sigprocmask */
	{ 2, s(struct getlogin_args),
	    getlogin },				/* 49 = getlogin */
	{ 1, s(struct setlogin_args),
	    setlogin },				/* 50 = setlogin */
	{ 1, s(struct acct_args),
	    acct },				/* 51 = acct */
	{ 0, 0,
	    sigpending },			/* 52 = sigpending */
	{ 2, s(struct sigaltstack_args),
	    sigaltstack },			/* 53 = sigaltstack */
	{ 3, s(struct ioctl_args),
	    ioctl },				/* 54 = ioctl */
	{ 1, s(struct reboot_args),
	    reboot },				/* 55 = reboot */
	{ 1, s(struct revoke_args),
	    revoke },				/* 56 = revoke */
	{ 2, s(struct symlink_args),
	    symlink },				/* 57 = symlink */
	{ 3, s(struct readlink_args),
	    readlink },				/* 58 = readlink */
	{ 3, s(struct execve_args),
	    execve },				/* 59 = execve */
	{ 1, s(struct umask_args),
	    umask },				/* 60 = umask */
	{ 1, s(struct chroot_args),
	    chroot },				/* 61 = chroot */
	{ 2, s(struct compat_43_fstat_args),
	    compat_43(fstat) },			/* 62 = compat_43 fstat */
	{ 4, s(struct compat_43_getkerninfo_args),
	    compat_43(getkerninfo) },		/* 63 = compat_43 getkerninfo */
	{ 0, 0,
	    compat_43(getpagesize) },		/* 64 = compat_43 getpagesize */
	{ 2, s(struct msync_args),
	    msync },				/* 65 = msync */
	{ 0, 0,
	    vfork },				/* 66 = vfork */
	{ 0, 0,
	    nosys },				/* 67 = obsolete vread */
	{ 0, 0,
	    nosys },				/* 68 = obsolete vwrite */
	{ 1, s(struct sbrk_args),
	    sbrk },				/* 69 = sbrk */
	{ 1, s(struct sstk_args),
	    sstk },				/* 70 = sstk */
	{ 6, s(struct compat_43_mmap_args),
	    compat_43(mmap) },			/* 71 = compat_43 mmap */
	{ 1, s(struct ovadvise_args),
	    ovadvise },				/* 72 = vadvise */
	{ 2, s(struct munmap_args),
	    munmap },				/* 73 = munmap */
	{ 3, s(struct mprotect_args),
	    mprotect },				/* 74 = mprotect */
	{ 3, s(struct madvise_args),
	    madvise },				/* 75 = madvise */
	{ 0, 0,
	    nosys },				/* 76 = obsolete vhangup */
	{ 0, 0,
	    nosys },				/* 77 = obsolete vlimit */
	{ 3, s(struct mincore_args),
	    mincore },				/* 78 = mincore */
	{ 2, s(struct getgroups_args),
	    getgroups },			/* 79 = getgroups */
	{ 2, s(struct setgroups_args),
	    setgroups },			/* 80 = setgroups */
	{ 0, 0,
	    getpgrp },				/* 81 = getpgrp */
	{ 2, s(struct setpgid_args),
	    setpgid },				/* 82 = setpgid */
	{ 3, s(struct setitimer_args),
	    setitimer },			/* 83 = setitimer */
	{ 0, 0,
	    compat_43(wait) },			/* 84 = compat_43 wait */
	{ 1, s(struct swapon_args),
	    swapon },				/* 85 = swapon */
	{ 2, s(struct getitimer_args),
	    getitimer },			/* 86 = getitimer */
	{ 2, s(struct compat_43_gethostname_args),
	    compat_43(gethostname) },		/* 87 = compat_43 gethostname */
	{ 2, s(struct compat_43_sethostname_args),
	    compat_43(sethostname) },		/* 88 = compat_43 sethostname */
	{ 0, 0,
	    getdtablesize },			/* 89 = getdtablesize */
	{ 2, s(struct dup2_args),
	    dup2 },				/* 90 = dup2 */
	{ 0, 0,
	    nosys },				/* 91 = unimplemented getdopt */
	{ 3, s(struct fcntl_args),
	    fcntl },				/* 92 = fcntl */
	{ 5, s(struct select_args),
	    select },				/* 93 = select */
	{ 0, 0,
	    nosys },				/* 94 = unimplemented setdopt */
	{ 1, s(struct fsync_args),
	    fsync },				/* 95 = fsync */
	{ 3, s(struct setpriority_args),
	    setpriority },			/* 96 = setpriority */
	{ 3, s(struct socket_args),
	    socket },				/* 97 = socket */
	{ 3, s(struct connect_args),
	    connect },				/* 98 = connect */
	{ 3, s(struct compat_43_accept_args),
	    compat_43(accept) },		/* 99 = compat_43 accept */
	{ 2, s(struct getpriority_args),
	    getpriority },			/* 100 = getpriority */
	{ 4, s(struct compat_43_send_args),
	    compat_43(send) },			/* 101 = compat_43 send */
	{ 4, s(struct compat_43_recv_args),
	    compat_43(recv) },			/* 102 = compat_43 recv */
	{ 1, s(struct sigreturn_args),
	    sigreturn },			/* 103 = sigreturn */
	{ 3, s(struct bind_args),
	    bind },				/* 104 = bind */
	{ 5, s(struct setsockopt_args),
	    setsockopt },			/* 105 = setsockopt */
	{ 2, s(struct listen_args),
	    listen },				/* 106 = listen */
	{ 0, 0,
	    nosys },				/* 107 = obsolete vtimes */
	{ 3, s(struct compat_43_sigvec_args),
	    compat_43(sigvec) },		/* 108 = compat_43 sigvec */
	{ 1, s(struct compat_43_sigblock_args),
	    compat_43(sigblock) },		/* 109 = compat_43 sigblock */
	{ 1, s(struct compat_43_sigsetmask_args),
	    compat_43(sigsetmask) },		/* 110 = compat_43 sigsetmask */
	{ 1, s(struct sigsuspend_args),
	    sigsuspend },			/* 111 = sigsuspend */
	{ 2, s(struct compat_43_sigstack_args),
	    compat_43(sigstack) },		/* 112 = compat_43 sigstack */
	{ 3, s(struct compat_43_recvmsg_args),
	    compat_43(recvmsg) },		/* 113 = compat_43 recvmsg */
	{ 3, s(struct compat_43_sendmsg_args),
	    compat_43(sendmsg) },		/* 114 = compat_43 sendmsg */
#ifdef TRACE
	{ 2, s(struct vtrace_args),
	    vtrace },				/* 115 = vtrace */
#else
	{ 0, 0,
	    nosys },				/* 115 = obsolete vtrace */
#endif
	{ 2, s(struct gettimeofday_args),
	    gettimeofday },			/* 116 = gettimeofday */
	{ 2, s(struct getrusage_args),
	    getrusage },			/* 117 = getrusage */
	{ 5, s(struct getsockopt_args),
	    getsockopt },			/* 118 = getsockopt */
#ifdef vax
	{ 1, s(struct resuba_args),
	    resuba },				/* 119 = resuba */
#else
	{ 0, 0,
	    nosys },				/* 119 = unimplemented resuba */
#endif
	{ 3, s(struct readv_args),
	    readv },				/* 120 = readv */
	{ 3, s(struct writev_args),
	    writev },				/* 121 = writev */
	{ 2, s(struct settimeofday_args),
	    settimeofday },			/* 122 = settimeofday */
	{ 3, s(struct fchown_args),
	    fchown },				/* 123 = fchown */
	{ 2, s(struct fchmod_args),
	    fchmod },				/* 124 = fchmod */
	{ 6, s(struct compat_43_recvfrom_args),
	    compat_43(recvfrom) },		/* 125 = compat_43 recvfrom */
	{ 2, s(struct compat_43_setreuid_args),
	    compat_43(setreuid) },		/* 126 = compat_43 setreuid */
	{ 2, s(struct compat_43_setregid_args),
	    compat_43(setregid) },		/* 127 = compat_43 setregid */
	{ 2, s(struct rename_args),
	    rename },				/* 128 = rename */
	{ 2, s(struct compat_43_truncate_args),
	    compat_43(truncate) },		/* 129 = compat_43 truncate */
	{ 2, s(struct compat_43_ftruncate_args),
	    compat_43(ftruncate) },		/* 130 = compat_43 ftruncate */
	{ 2, s(struct flock_args),
	    flock },				/* 131 = flock */
	{ 2, s(struct mkfifo_args),
	    mkfifo },				/* 132 = mkfifo */
	{ 6, s(struct sendto_args),
	    sendto },				/* 133 = sendto */
	{ 2, s(struct shutdown_args),
	    shutdown },				/* 134 = shutdown */
	{ 4, s(struct socketpair_args),
	    socketpair },			/* 135 = socketpair */
	{ 2, s(struct mkdir_args),
	    mkdir },				/* 136 = mkdir */
	{ 1, s(struct rmdir_args),
	    rmdir },				/* 137 = rmdir */
	{ 2, s(struct utimes_args),
	    utimes },				/* 138 = utimes */
	{ 0, 0,
	    nosys },				/* 139 = obsolete 4.2 sigreturn */
	{ 2, s(struct adjtime_args),
	    adjtime },				/* 140 = adjtime */
	{ 3, s(struct compat_43_getpeername_args),
	    compat_43(getpeername) },		/* 141 = compat_43 getpeername */
	{ 0, 0,
	    compat_43(gethostid) },		/* 142 = compat_43 gethostid */
	{ 1, s(struct compat_43_sethostid_args),
	    compat_43(sethostid) },		/* 143 = compat_43 sethostid */
	{ 2, s(struct compat_43_getrlimit_args),
	    compat_43(getrlimit) },		/* 144 = compat_43 getrlimit */
	{ 2, s(struct compat_43_setrlimit_args),
	    compat_43(setrlimit) },		/* 145 = compat_43 setrlimit */
	{ 2, s(struct compat_43_killpg_args),
	    compat_43(killpg) },		/* 146 = compat_43 killpg */
	{ 0, 0,
	    setsid },				/* 147 = setsid */
	{ 4, s(struct quotactl_args),
	    quotactl },				/* 148 = quotactl */
	{ 0, 0,
	    compat_43(quota) },			/* 149 = compat_43 quota */
	{ 3, s(struct compat_43_getsockname_args),
	    compat_43(getsockname) },		/* 150 = compat_43 getsockname */
	{ 0, 0,
	    nosys },				/* 151 = unimplemented */
	{ 0, 0,
	    nosys },				/* 152 = unimplemented */
	{ 0, 0,
	    nosys },				/* 153 = unimplemented */
	{ 0, 0,
	    nosys },				/* 154 = unimplemented */
#ifdef NFS
	{ 2, s(struct nfssvc_args),
	    nfssvc },				/* 155 = nfssvc */
#else
	{ 0, 0,
	    nosys },				/* 155 = unimplemented nfssvc */
#endif
	{ 4, s(struct compat_43_getdirentries_args),
	    compat_43(getdirentries) },		/* 156 = compat_43 getdirentries */
	{ 2, s(struct statfs_args),
	    statfs },				/* 157 = statfs */
	{ 2, s(struct fstatfs_args),
	    fstatfs },				/* 158 = fstatfs */
	{ 0, 0,
	    nosys },				/* 159 = unimplemented */
	{ 0, 0,
	    nosys },				/* 160 = unimplemented */
#ifdef NFS
	{ 2, s(struct getfh_args),
	    getfh },				/* 161 = getfh */
#else
	{ 0, 0,
	    nosys },				/* 161 = unimplemented getfh */
#endif
	{ 0, 0,
	    nosys },				/* 162 = unimplemented getdomainname */
	{ 0, 0,
	    nosys },				/* 163 = unimplemented setdomainname */
	{ 0, 0,
	    nosys },				/* 164 = unimplemented */
	{ 0, 0,
	    nosys },				/* 165 = unimplemented */
	{ 0, 0,
	    nosys },				/* 166 = unimplemented */
	{ 0, 0,
	    nosys },				/* 167 = unimplemented */
	{ 0, 0,
	    nosys },				/* 168 = unimplemented */
	{ 0, 0,
	    nosys },				/* 169 = unimplemented semsys */
	{ 0, 0,
	    nosys },				/* 170 = unimplemented msgsys */
#if defined(SYSVSHM) && !defined(alpha)
	{ 4, s(struct compat_43_shmsys_args),
	    compat_43(shmsys) },		/* 171 = compat_43 shmsys */
#else
	{ 0, 0,
	    nosys },				/* 171 = unimplemented shmsys */
#endif
	{ 0, 0,
	    nosys },				/* 172 = unimplemented */
	{ 0, 0,
	    nosys },				/* 173 = unimplemented */
	{ 0, 0,
	    nosys },				/* 174 = unimplemented */
	{ 0, 0,
	    nosys },				/* 175 = unimplemented */
	{ 0, 0,
	    nosys },				/* 176 = unimplemented */
	{ 0, 0,
	    nosys },				/* 177 = unimplemented */
	{ 0, 0,
	    nosys },				/* 178 = unimplemented */
	{ 0, 0,
	    nosys },				/* 179 = unimplemented */
	{ 0, 0,
	    nosys },				/* 180 = unimplemented */
	{ 1, s(struct setgid_args),
	    setgid },				/* 181 = setgid */
	{ 1, s(struct setegid_args),
	    setegid },				/* 182 = setegid */
	{ 1, s(struct seteuid_args),
	    seteuid },				/* 183 = seteuid */
#ifdef LFS
	{ 3, s(struct lfs_bmapv_args),
	    lfs_bmapv },			/* 184 = lfs_bmapv */
	{ 3, s(struct lfs_markv_args),
	    lfs_markv },			/* 185 = lfs_markv */
	{ 2, s(struct lfs_segclean_args),
	    lfs_segclean },			/* 186 = lfs_segclean */
	{ 2, s(struct lfs_segwait_args),
	    lfs_segwait },			/* 187 = lfs_segwait */
#else
	{ 0, 0,
	    nosys },				/* 184 = unimplemented lfs_bmapv */
	{ 0, 0,
	    nosys },				/* 185 = unimplemented lfs_markv */
	{ 0, 0,
	    nosys },				/* 186 = unimplemented lfs_segclean */
	{ 0, 0,
	    nosys },				/* 187 = unimplemented lfs_segwait */
#endif
	{ 2, s(struct stat_args),
	    stat },				/* 188 = stat */
	{ 2, s(struct fstat_args),
	    fstat },				/* 189 = fstat */
	{ 2, s(struct lstat_args),
	    lstat },				/* 190 = lstat */
	{ 2, s(struct pathconf_args),
	    pathconf },				/* 191 = pathconf */
	{ 2, s(struct fpathconf_args),
	    fpathconf },			/* 192 = fpathconf */
	{ 0, 0,
	    nosys },				/* 193 = unimplemented */
	{ 2, s(struct getrlimit_args),
	    getrlimit },			/* 194 = getrlimit */
	{ 2, s(struct setrlimit_args),
	    setrlimit },			/* 195 = setrlimit */
	{ 4, s(struct getdirentries_args),
	    getdirentries },			/* 196 = getdirentries */
	{ 7, s(struct mmap_args),
	    mmap },				/* 197 = mmap */
	{ 0, 0,
	    nosys },				/* 198 = __syscall */
	{ 4, s(struct lseek_args),
	    lseek },				/* 199 = lseek */
	{ 3, s(struct truncate_args),
	    truncate },				/* 200 = truncate */
	{ 3, s(struct ftruncate_args),
	    ftruncate },			/* 201 = ftruncate */
	{ 6, s(struct __sysctl_args),
	    __sysctl },				/* 202 = __sysctl */
	{ 2, s(struct mlock_args),
	    mlock },				/* 203 = mlock */
	{ 2, s(struct munlock_args),
	    munlock },				/* 204 = munlock */
	{ 1, s(struct undelete_args),
	    undelete },				/* 205 = undelete */
	{ 0, 0,
	    nosys },				/* 206 = unimplemented */
	{ 0, 0,
	    nosys },				/* 207 = unimplemented */
	{ 0, 0,
	    nosys },				/* 208 = unimplemented */
	{ 0, 0,
	    nosys },				/* 209 = unimplemented */
	{ 0, 0,
	    nosys },				/* 210 = unimplemented */
	{ 0, 0,
	    nosys },				/* 211 = unimplemented */
	{ 0, 0,
	    nosys },				/* 212 = unimplemented */
	{ 0, 0,
	    nosys },				/* 213 = unimplemented */
	{ 0, 0,
	    nosys },				/* 214 = unimplemented */
	{ 0, 0,
	    nosys },				/* 215 = unimplemented */
	{ 0, 0,
	    nosys },				/* 216 = unimplemented */
	{ 0, 0,
	    nosys },				/* 217 = unimplemented */
	{ 0, 0,
	    nosys },				/* 218 = unimplemented */
	{ 0, 0,
	    nosys },				/* 219 = unimplemented */
	{ 0, 0,
	    nosys },				/* 220 = unimplemented semctl */
	{ 0, 0,
	    nosys },				/* 221 = unimplemented semget */
	{ 0, 0,
	    nosys },				/* 222 = unimplemented semop */
	{ 0, 0,
	    nosys },				/* 223 = unimplemented semconfig */
	{ 0, 0,
	    nosys },				/* 224 = unimplemented msgctl */
	{ 0, 0,
	    nosys },				/* 225 = unimplemented msgget */
	{ 0, 0,
	    nosys },				/* 226 = unimplemented msgsnd */
	{ 0, 0,
	    nosys },				/* 227 = unimplemented msgrcv */
#if defined(SYSVSHM) && 0
	{ 3, s(struct shmat_args),
	    shmat },				/* 228 = shmat */
	{ 3, s(struct shmctl_args),
	    shmctl },				/* 229 = shmctl */
	{ 1, s(struct shmdt_args),
	    shmdt },				/* 230 = shmdt */
	{ 3, s(struct shmget_args),
	    shmget },				/* 231 = shmget */
#else
	{ 0, 0,
	    nosys },				/* 228 = unimplemented shmat */
	{ 0, 0,
	    nosys },				/* 229 = unimplemented shmctl */
	{ 0, 0,
	    nosys },				/* 230 = unimplemented shmdt */
	{ 0, 0,
	    nosys },				/* 231 = unimplemented shmget */
#endif
};

int	nsysent= sizeof(sysent) / sizeof(sysent[0]);
