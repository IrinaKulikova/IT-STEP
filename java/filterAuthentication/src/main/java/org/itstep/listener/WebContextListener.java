package org.itstep.listener;

import org.itstep.dao.UserDao;
import org.itstep.dao.UserDaoFactory;
import org.itstep.service.CheckUserService;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;
import javax.servlet.annotation.WebListener;

/**
 * javax.servlet.ServletContextListener
 * Этот Listener позволяет разработчику "уловить" момент когда ServletContext инициализируется либо уничтожается. Его можно использовать, например, для открытия соединения с базой данных в момент создания контекста и закрытия соединения в момент уничтожения контекста.
 * Метод                                                                                          Описание                             _
 * void contextDestroyed(ServletContextEvent sce)                   Вызывается перед тем как ServletContext
 *                                                                                                    будет уничтожен
 *
 * void contextInitialized(ServletContextEvent sce)                   Вызывается сразу после создания
 *                                                                                                       ServletContext-a
 * _                                                                                                                                                  _
 */

@WebListener
public class WebContextListener implements ServletContextListener {
    @Override
    public void contextInitialized(ServletContextEvent sce) {
        // TODO: Ваш код здесь
        System.out.println("Init application");
        ApplicationContext context = new ClassPathXmlApplicationContext("spring-config.xml");
        UserDaoFactory factory = context.getBean("userDaoFactory", UserDaoFactory.class);
        CheckUserService service = context.getBean("checkUserServiceser", CheckUserService.class);
    }

    @Override
    public void contextDestroyed(ServletContextEvent sce) {

    }
}