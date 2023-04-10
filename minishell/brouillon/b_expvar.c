void	ft_switchvar(t_cmd *cmd, char *toinc, int dollarlen, int i)
{
	char	*new;

	new = malloc((ft_strlen(cmd->arg[i]) + ft_strlen(toinc) - ft_strlen(dollarlen + 1)) * sizeof(char));

}

char	*ft_lookintoenv(t_env *env, char *tmp)
{
	char	*str;
	t_env	*buff;

	buff = ft_isenv(env, tmp);
	free(tmp);
	if (buff == NULL)
		return (NULL);
	else
		return (ft_strdup(env->content));

}

void	ft_replace_var(t_cmd *cmd, int i, t_env *env, char c)
{
	char	*tmp;
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (cmd->arg[i][j] != '$')
		j++;
	j++;
	tmp = malloc((ms_strlen(&cmd->arg[i][j], ' ') + 1) * sizeof(char)); // le ' ' peux t il etre remplacer par c?
	while (cmd->arg[i][j] != c && cmd->arg[i][j] != '\0')
	{
		tmp[k] = cmd->arg[i][j];
		k++;
		j++;
	}
	tmp[k] = '\0';
	tmp = ft_lookintoenv(env, tmp);
	ft_switchvar(cmd, tmp, k, i);
}