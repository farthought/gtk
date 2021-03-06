#include <gtk/gtk.h>

#define NAME    "root"
#define PWD     "123456"

//将登陆窗体独立成一个结构体

struct login_widget{
	GtkWidget *window; //主窗体
	GtkWidget *label_tips; //用于信息提示的标签
	GtkWidget *button_login; //两个按钮，一个点击后登录，一个点击后退出
	GtkWidget *button_exit;
	GtkWidget *entry_username; //两个文本框，用于输入用户名和密码
	GtkWidget *entry_pwd;
	GtkWidget *label_username; //两个标签用于显示username文本框和password文本框提示
	GtkWidget *label_pwd;
	GtkWidget *vbox; //垂直布局盒子，包含以下三个水平布局盒子
	GtkWidget *hbox_username; //包含用户名提示标签和用户名文本框，下面的HBOX作用类似
	GtkWidget *hbox_pwd;
	GtkWidget *hbox_button;
}wgt;

void gtk_win_destroy(GtkWidget *widget,gpointer data)
{
	gtk_main_quit();
}

//登录验证函数，点击login按钮时调用

void login(GtkWidget *widget,gpointer data)
{
	gchar *name;
	gchar *pwd;
	struct login_widget *wgt;

	wgt = (struct loging_widget *)data;

	//获取输入的信息

	name = gtk_entry_get_text(GTK_ENTRY(wgt->entry_username));
	pwd = gtk_entry_get_text(GTK_ENTRY(wgt->entry_pwd));

	if((strcmp(name,NAME) == 0) && (strcmp(pwd,PWD) == 0))
	{
		gtk_label_set_text(GTK_LABEL(wgt->label_tips),"Welcome to GTK+-2.0");
	}
	else
	{
		gtk_label_set_text(GTK_LABEL(wgt->label_tips),"Invalid user name or password.");
	}
}
	static gint
entry_button_press (GtkWidget      *widget,                                                                                      
		GdkEventButton *event)
{
	if (event->button == 3 && event->type == GDK_BUTTON_PRESS) {
		return TRUE;
	}

	return FALSE;
}


void init_login_widget()
{
	wgt.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	wgt.label_tips = gtk_label_new("Welcome,please login first");
	wgt.button_login = gtk_button_new_with_label("login");
	wgt.button_exit = gtk_button_new_with_label("exit");
	wgt.entry_username = gtk_entry_new_with_max_length(10);
	wgt.entry_pwd = gtk_entry_new_with_max_length(100);
	wgt.label_username = gtk_label_new("User name :");
	wgt.label_pwd = gtk_label_new("Password :");
	wgt.vbox = gtk_vbox_new(FALSE,20);
	wgt.hbox_username = gtk_hbox_new(FALSE,20);
	wgt.hbox_pwd = gtk_hbox_new(FALSE,20);
	wgt.hbox_button = gtk_hbox_new(FALSE,20);

	//设置窗体

	gtk_window_set_title(GTK_WINDOW(wgt.window),"System login");
	gtk_window_set_resizable(GTK_WINDOW(wgt.window),FALSE);

	//设置布局盒子

	gtk_box_pack_start(GTK_BOX(wgt.hbox_username),wgt.label_username,TRUE,FALSE,10);
	gtk_box_pack_start(GTK_BOX(wgt.hbox_username),wgt.entry_username,TRUE,FALSE,10);
	gtk_box_pack_start(GTK_BOX(wgt.hbox_pwd),wgt.label_pwd,TRUE,FALSE,10);
	gtk_box_pack_start(GTK_BOX(wgt.hbox_pwd),wgt.entry_pwd,TRUE,FALSE,10);
	gtk_box_pack_start(GTK_BOX(wgt.hbox_button),wgt.button_login,TRUE,FALSE,10);
	gtk_box_pack_start(GTK_BOX(wgt.hbox_button),wgt.button_exit,TRUE,FALSE,10);

	gtk_box_pack_start(GTK_BOX(wgt.vbox),wgt.label_tips,TRUE,FALSE,10);
	gtk_box_pack_start(GTK_BOX(wgt.vbox),wgt.hbox_username,TRUE,FALSE,10);
	gtk_box_pack_start(GTK_BOX(wgt.vbox),wgt.hbox_pwd,TRUE,FALSE,10);
	gtk_box_pack_start(GTK_BOX(wgt.vbox),wgt.hbox_button,TRUE,FALSE,10);

	//设置密码框不可见，用户输入时显示“#”
	gtk_entry_set_alignment(GTK_ENTRY(wgt.entry_pwd),0.05);
	gtk_widget_set_size_request(GTK_WIDGET(wgt.entry_pwd),50,28);
	gtk_widget_set_can_default(GTK_WIDGET(wgt.entry_pwd),TRUE);
	gtk_widget_grab_default(GTK_WIDGET(wgt.entry_pwd));
	gtk_widget_set_can_focus(GTK_WIDGET(wgt.entry_pwd),TRUE);
	gtk_widget_grab_focus (GTK_WIDGET(wgt.entry_pwd));
	gtk_entry_set_visibility(GTK_ENTRY(wgt.entry_pwd),FALSE);
	g_object_set(G_OBJECT(wgt.entry_pwd), "caps-lock-warning", TRUE, NULL);

	gtk_entry_set_invisible_char(GTK_ENTRY(wgt.entry_pwd),'#');
	gtk_entry_set_activates_default(GTK_ENTRY(wgt.entry_pwd),TRUE);
//	g_object_set_property(G_OBJECT(wgt.entry_pwd), "caps-lock-warning", FALSE);
	gtk_widget_set_sensitive (GTK_WIDGET(wgt.entry_pwd), TRUE);
	g_signal_connect (wgt.entry_pwd, "button_press_event",
			G_CALLBACK (entry_button_press), NULL);
	gtk_entry_set_icon_from_gicon(GTK_ENTRY(wgt.entry_pwd),GTK_ENTRY_ICON_PRIMARY,g_icon_new_for_string("/usr/lib/cinnamon-screensaver/image/psw.png",NULL)); 

	g_signal_connect(GTK_OBJECT(wgt.button_login),"clicked",GTK_SIGNAL_FUNC(login),&wgt);
	g_signal_connect(GTK_OBJECT(wgt.window),"destroy",GTK_SIGNAL_FUNC(gtk_win_destroy),NULL);
	g_signal_connect(GTK_OBJECT(wgt.button_exit),"clicked",GTK_SIGNAL_FUNC(gtk_win_destroy),NULL);

	gtk_container_add(GTK_CONTAINER(wgt.window),wgt.vbox);

	gtk_widget_show_all(wgt.window);
}

int main(int argc,char *argv[])
{
	gtk_init(&argc,&argv);

	init_login_widget();

	gtk_main();

	return 0;
}
